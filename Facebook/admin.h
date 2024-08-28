#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"
#include "account.h"
#include <string>

using std::string;

class Admin : public Person {
public:
    Admin(const string& name, const string& address, const string& email, const string& phone, Account* account);

    void block_user(Person* customer);
    void unblock_user(Person* customer);
    void enable_page(const string& page);
    void disable_page(const string& page);
};

#endif // ADMIN_H
