#ifndef COMMENT_H
#define COMMENT_H

#include <string>

using std::string;

class Comment {
private:
    string comment_id;
    string text;
    int total_likes;
    string owner; // Assuming owner is a string

public:
    Comment(const string& id, const string& text, int total_likes, const string& owner)
        : comment_id(id), text(text), total_likes(total_likes), owner(owner) {}

    // Optionally, you might want to add getters for these private members
    // string get_comment_id() const { return comment_id; }
    // string get_text() const { return text; }
    // int get_total_likes() const { return total_likes; }
    // string get_owner() const { return owner; }
};

#endif // COMMENT_H
