#ifndef CONSTANTS_H
#define CONSTANTS_H

enum class QuestionStatus {
    OPEN = 1,
    CLOSED,
    ON_HOLD,
    DELETED
};

enum class QuestionClosingRemark {
    DUPLICATE = 1,
    OFF_TOPIC,
    TOO_BROAD,
    NOT_CONSTRUCTIVE,
    NOT_A_REAL_QUESTION,
    PRIMARILY_OPINION_BASED
};

enum class AccountStatus {
    ACTIVE = 1,
    CLOSED,
    CANCELED,
    BLACKLISTED,
    BLOCKED
};

#endif 