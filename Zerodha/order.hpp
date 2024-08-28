#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <map>
#include "constants.hpp"

// Forward declaration of OrderPart class
class OrderPart;

class Order {
protected:
    int order_id;
    bool is_buy_order;
    OrderStatus status;
    TimeEnforcementType time_enforcement;
    std::string creation_time; // Use string to represent datetime for simplicity

    std::map<int, OrderPart*> parts;

public:
    Order(int id);

    // Virtual destructor for base class
    virtual ~Order();

    void set_status(OrderStatus status);
    virtual void save_in_DB(); // Pure virtual function to be implemented in derived classes

    void add_order_parts(const std::map<int, OrderPart*>& new_parts);
};

#endif // ORDER_H
