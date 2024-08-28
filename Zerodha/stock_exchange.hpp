#ifndef STOCK_EXCHANGE_H
#define STOCK_EXCHANGE_H

#include "order.hpp" // Include Order class
#include "constants.hpp" // Include constants if needed

class StockExchange {
private:
    static StockExchange* instance; // Static pointer to the single instance
    // Private constructor for Singleton pattern
    StockExchange() = default;

public:
    // Deleted copy constructor and assignment operator to prevent copying
    StockExchange(const StockExchange&) = delete;
    StockExchange& operator=(const StockExchange&) = delete;

    // Static method to get the singleton instance
    static StockExchange* get_instance() {
        if (!instance) {
            instance = new StockExchange();
        }
        return instance;
    }

    // Method to place an order
    ReturnStatus place_order(const Order& order);

    // Destructor to clean up allocated memory
    ~StockExchange() {
        // Clean up any resources if necessary
    }
};

#endif // STOCK_EXCHANGE_H
