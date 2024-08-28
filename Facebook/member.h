#ifndef MEMBER_H
#define MEMBER_H

#include "person.h"
#include "constants.h"
#include "connection_invitation.h"
#include "profile.h"
#include <vector>
#include <ctime>

using std::vector;

class Member : public Person {
private:
    string member_id;
    std::tm date_of_membership;
    Profile profile;
    vector<Member*> member_follows;
    vector<Member*> member_connections;
    vector<string> page_follows;
    vector<Member*> member_suggestions;
    vector<ConnectionInvitation*> connection_invitations;
    vector<string> group_follows;

public:
    Member(const string& id, const std::tm& date_of_membership, const string& name);

    void send_message(const string& message);
    void create_post(const string& post);
    void send_connection_invitation(ConnectionInvitation* invitation);
    void search_member_suggestions();
};

#endif // MEMBER_H
