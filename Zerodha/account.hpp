#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "constants.hpp"

// Forward declaration of Address and LimitOrder classes
class Address;
class LimitOrder;

class Account {
protected:
    int id;
    std::string password;
    std::string name;
    Address* address;
    std::string email;
    std::string phone;
    AccountStatus status;

public:
    Account(int id, const std::string& password, const std::string& name, Address* address, const std::string& email, const std::string& phone, AccountStatus status = AccountStatus::NONE);

    virtual ~Account();

    virtual void reset_password();
};

#endif // ACCOUNT_H
