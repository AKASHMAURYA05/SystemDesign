#include "order.hpp"
// #include "order_part.hpp" // Include OrderPart class

#include <chrono>
#include <iomanip>
#include <sstream>

// Initialize static members if necessary

Order::Order(int id)
    : order_id(id), is_buy_order(false), status(OrderStatus::OPEN),
      time_enforcement(TimeEnforcementType::ON_THE_OPEN) {
    // Get current time in YYYY-MM-DD HH:MM:SS format
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_time_t), "%Y-%m-%d %H:%M:%S");
    creation_time = ss.str();
}

Order::~Order() {
    // Cleanup if necessary
}

void Order::set_status(OrderStatus status) {
    this->status = status;
}

void Order::save_in_DB() {
    // Implement database save logic here
}

void Order::add_order_parts(const std::map<int, OrderPart*>& new_parts) {
    for (const auto& part : new_parts) {
        parts[part.first] = part.second;
    }
}
