#include "member.hpp"
#include "order.hpp"
#include "stock_exchange.hpp"
#include <ctime>
#include <sstream>

Member::Member(int id, const std::string& password, const std::string& name, Address* address, const std::string& email, const std::string& phone, AccountStatus status)
    : Account(id, password, name, address, email, phone, status), available_funds_for_trading(0.0) {
    // Initialize date_of_membership
    std::time_t now = std::time(nullptr);
    std::tm* tm = std::localtime(&now);
    std::stringstream ss;
    ss << (tm->tm_year + 1900) << '-' << (tm->tm_mon + 1) << '-' << tm->tm_mday;
    date_of_membership = ss.str();
}

ReturnStatus Member::place_sell_limit_order(int stock_id, int quantity, double limit_price, TimeEnforcementType enforcement_type) {
    if (stock_positions.find(stock_id) == stock_positions.end()) {
        return ReturnStatus::NO_STOCK_POSITION;
    }

    int stock_quantity = stock_positions[stock_id];
    if (stock_quantity < quantity) {
        return ReturnStatus::INSUFFICIENT_QUANTITY;
    }

    LimitOrder* order = new LimitOrder(stock_id, quantity, limit_price, enforcement_type);
    order->set_is_buy_order(false);
    order->save_in_DB();
    ReturnStatus success = StockExchange::get_instance()->place_order(*order);
    if (success != ReturnStatus::SUCCESS) {
        order->set_status(OrderStatus::FAILED);
        order->save_in_DB();
        delete order;
    } else {
        active_orders[order->get_order_id()] = order;
    }
    return success;
}

ReturnStatus Member::place_buy_limit_order(int stock_id, int quantity, double limit_price, TimeEnforcementType enforcement_type) {
    if (available_funds_for_trading < quantity * limit_price) {
        return ReturnStatus::INSUFFICIENT_FUNDS;
    }

    LimitOrder* order = new LimitOrder(stock_id, quantity, limit_price, enforcement_type);
    order->set_is_buy_order(true);
    order->save_in_DB();
    ReturnStatus success = StockExchange::get_instance()->place_order(*order);
    if (success != ReturnStatus::SUCCESS) {
        order->set_status(OrderStatus::FAILED);
        order->save_in_DB();
        delete order;
    } else {
        active_orders[order->get_order_id()] = order;
    }
    return success;
}

void Member::callback_stock_exchange(int order_id, const std::map<int, OrderPart*>& order_parts, OrderStatus status) {
    auto it = active_orders.find(order_id);
    if (it != active_orders.end()) {
        LimitOrder* order = it->second;
        order->add_order_parts(order_parts);
        order->set_status(status);
        order->update_in_DB();

        if (status == OrderStatus::FILLED || status == OrderStatus::CANCELLED) {
            active_orders.erase(it);
            delete order;
        }
    }
}
