#ifndef CONSTANTS_H
#define CONSTANTS_H

enum class ReturnStatus {
    SUCCESS = 1,
    FAIL,
    INSUFFICIENT_FUNDS,
    INSUFFICIENT_QUANTITY,
    NO_STOCK_POSITION
};

enum class OrderStatus {
    OPEN = 1,
    FILLED,
    PARTIALLY_FILLED,
    CANCELLED
};

enum class TimeEnforcementType {
    GOOD_TILL_CANCELLED = 1,
    FILL_OR_KILL,
    IMMEDIATE_OR_CANCEL,
    ON_THE_OPEN,
    ON_THE_CLOSE
};

enum class AccountStatus {
    ACTIVE = 1,
    CLOSED,
    CANCELED,
    BLACKLISTED,
    NONE
};

#endif // CONSTANTS_H
