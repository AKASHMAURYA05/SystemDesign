#ifndef MEMBER_H
#define MEMBER_H

#include "account.hpp"
#include "order.hpp"
#include <map>
#include <vector>

// Forward declaration of StockExchange class
class StockExchange;

class Member : public Account {
private:
    double available_funds_for_trading;
    std::string date_of_membership; // Use string to represent date
    std::map<int, int> stock_positions; // stock_id -> quantity
    std::map<int, LimitOrder*> active_orders;

public:
    Member(int id, const std::string& password, const std::string& name, Address* address, const std::string& email, const std::string& phone, AccountStatus status = AccountStatus::NONE);

    ReturnStatus place_sell_limit_order(int stock_id, int quantity, double limit_price, TimeEnforcementType enforcement_type);
    ReturnStatus place_buy_limit_order(int stock_id, int quantity, double limit_price, TimeEnforcementType enforcement_type);

    void callback_stock_exchange(int order_id, const std::map<int, OrderPart*>& order_parts, OrderStatus status);
};

#endif // MEMBER_H
