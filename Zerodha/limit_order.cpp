#include "limit_order.hpp"

LimitOrder::LimitOrder(int id, double price_limit)
    : Order(id), price_limit(price_limit) {
    // Additional initialization if needed
}

double LimitOrder::get_price_limit() const {
    return price_limit;
}
