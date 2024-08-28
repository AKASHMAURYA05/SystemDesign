#ifndef POST_H
#define POST_H

#include <string>

using std::string;

class Post {
private:
    string post_id;
    string text;
    int total_likes;
    int total_shares;
    string owner; // Assuming owner is a string

public:
    Post(const string& id, const string& text, int total_likes, int total_shares, const string& owner)
        : post_id(id), text(text), total_likes(total_likes), total_shares(total_shares), owner(owner) {}

    // Optionally, you might want to add getters for these private members
    // string get_post_id() const { return post_id; }
    // string get_text() const { return text; }
    // int get_total_likes() const { return total_likes; }
    // int get_total_shares() const { return total_shares; }
    // string get_owner() const { return owner; }
};

#endif // POST_H
