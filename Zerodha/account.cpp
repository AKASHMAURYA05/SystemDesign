#include "account.hpp"

Account::Account(int id, const std::string& password, const std::string& name, Address* address, const std::string& email, const std::string& phone, AccountStatus status)
    : id(id), password(password), name(name), address(address), email(email), phone(phone), status(status) {
}

Account::~Account() {
    delete address; // Assuming address is dynamically allocated
}

void Account::reset_password() {
    // Implementation for resetting password
}
