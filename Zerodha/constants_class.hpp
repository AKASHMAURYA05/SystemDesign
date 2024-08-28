#ifndef CONSTANTS_CLASS_H
#define CONSTANTS_CLASS_H

class Constants {
private:
    static const int MONEY_TRANSFER_LIMIT = 100000; // Static constant

public:
    static int get_money_transfer_limit() {
        return MONEY_TRANSFER_LIMIT;
    }
};

#endif // CONSTANTS_CLASS_H
