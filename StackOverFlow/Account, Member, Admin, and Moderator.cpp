#include <string>
#include <vector>
#include "constants.h"

using namespace std;

class Account {
private:
    string id;
    string password;
    string name;
    string address;
    string email;
    string phone;
    AccountStatus status;
    int reputation;

public:
    Account(const string& id, const string& password, const string& name,
            const string& address, const string& email, const string& phone,
            AccountStatus status = AccountStatus::Active)
        : id(id), password(password), name(name), address(address),
          email(email), phone(phone), status(status), reputation(0) {}

    void reset_password() {
        // Implementation not provided
    }

    // Getter methods
    int get_reputation() const { return reputation; }
    string get_email() const { return email; }
};

class Member {
private:
    Account account;
    vector<string> badges;

public:
    Member(const Account& account) : account(account) {}

    int get_reputation() const {
        return account.get_reputation();
    }

    string get_email() const {
        return account.get_email();
    }

    void create_question(const string& question) {
        // Implementation not provided
    }

    void create_tag(const string& tag) {
        // Implementation not provided
    }
};

class Admin : public Member {
public:
    Admin(const Account& account) : Member(account) {}

    void block_member(const Member& member) {
        // Implementation not provided
    }

    void unblock_member(const Member& member) {
        // Implementation not provided
    }
};

class Moderator : public Member {
public:
    Moderator(const Account& account) : Member(account) {}

    void close_question(const string& question) {
        // Implementation not provided
    }

    void undelete_question(const string& question) {
        // Implementation not provided
    }
};
