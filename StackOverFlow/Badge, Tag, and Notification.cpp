#include <string>
#include <ctime>

using namespace std;

class Badge {
private:
    string name;
    string description;

public:
    Badge(const string& name, const string& description)
        : name(name), description(description) {}
};

class Tag {
private:
    string name;
    string description;
    int daily_asked_frequency;
    int weekly_asked_frequency;

public:
    Tag(const string& name, const string& description)
        : name(name), description(description),
          daily_asked_frequency(0), weekly_asked_frequency(0) {}
};

class Notification {
private:
    int notification_id;
    time_t created_on;
    string content;

public:
    Notification(int id, const string& content)
        : notification_id(id), content(content) {
        time(&created_on);
    }

    void send_notification() {
        // Implementation not provided
    }
};
