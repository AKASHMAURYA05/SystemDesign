#ifndef LIMIT_ORDER_H
#define LIMIT_ORDER_H

#include "order.hpp"

class LimitOrder : public Order {
private:
    double price_limit;

public:
    LimitOrder(int id, double price_limit);

    // Additional methods specific to LimitOrder
    double get_price_limit() const;
};

#endif // LIMIT_ORDER_H
