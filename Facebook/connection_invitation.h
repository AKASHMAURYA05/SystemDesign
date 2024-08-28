#ifndef CONNECTION_INVITATION_H
#define CONNECTION_INVITATION_H

#include "constants.h"
#include "member.h"
#include <ctime>
#include <string>

using std::string;

class ConnectionInvitation {
private:
    Member* member_invited;
    ConnectionInvitationStatus status;
    std::tm date_created;
    std::tm date_updated;

public:
    ConnectionInvitation(Member* member_invited, const string& name, ConnectionInvitationStatus status = ConnectionInvitationStatus::PENDING);

    void accept_connection();
    void reject_connection();
};

#endif // CONNECTION_INVITATION_H
