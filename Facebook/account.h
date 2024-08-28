#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "constants.h"
#include <string>

using std::string;

class Account {
private:
    string id;
    string password;
    AccountStatus status;

public:
    Account(const string& id, const string& password, AccountStatus status = AccountStatus::ACTIVE)
        : id(id), password(password), status(status) {}

    void reset_password();
};

#endif // ACCOUNT_H
