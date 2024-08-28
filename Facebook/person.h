#ifndef PERSON_H
#define PERSON_H

#include "constants.h"
#include "profile.h"
#include "account.h"

#include <string>

using std::string;

class Person {
protected:
    string name;
    string address;
    string email;
    string phone;
    Account* account;

public:
    Person(const string& name, const string& address, const string& email, const string& phone, Account* account)
        : name(name), address(address), email(email), phone(phone), account(account) {}
};

#endif // PERSON_H
