#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

using std::string;

class Message {
private:
    string message_id;
    string sent_to;
    string message_body;
    string media; // Assuming media is stored as a string

public:
    Message(const string& id, const string& sent_to, const string& body, const string& media)
        : message_id(id), sent_to(sent_to), message_body(body), media(media) {}

    void add_member(const string& member) {
        // Implementation goes here
    }

    // Optionally, you might want to add getters for these private members
    // string get_message_id() const { return message_id; }
    // string get_sent_to() const { return sent_to; }
    // string get_message_body() const { return message_body; }
    // string get_media() const { return media; }
};

#endif // MESSAGE_H
