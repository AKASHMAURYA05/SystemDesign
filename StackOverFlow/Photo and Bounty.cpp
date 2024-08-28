#include <string>
#include <ctime>

using namespace std;

// Forward declaration of Member class
class Member;

class Photo {
private:
    int photo_id;
    string photo_path;
    time_t creation_date;
    Member* creating_member;

public:
    Photo(int id, const string& path, Member* member)
        : photo_id(id), photo_path(path), creating_member(member) {
        time(&creation_date);
    }

    void delete_photo() {
        // Implementation not provided
    }
};

class Bounty {
private:
    int reputation;
    time_t expiry;

public:
    Bounty(int rep, time_t exp)
        : reputation(rep), expiry(exp) {}

    void modify_reputation(int new_reputation) {
        // Implementation not provided
    }
};