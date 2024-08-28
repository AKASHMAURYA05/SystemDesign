#ifndef CONSTANTS_H
#define CONSTANTS_H

enum class ConnectionInvitationStatus {
    PENDING = 1,
    ACCEPTED,
    REJECTED,
    CANCELED
};

enum class AccountStatus {
    ACTIVE = 1,
    CLOSED,
    CANCELED,
    BLACKLISTED,
    DISABLED
};

#endif // CONSTANTS_H
