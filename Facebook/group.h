#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <vector>
#include "member.h" // Include Member class if needed

using std::string;
using std::vector;

class Group {
private:
    string group_id;
    string name;
    string description;
    int total_members;
    vector<string> members; // Assuming members are stored as strings for simplicity

public:
    Group(const string& id, const string& name, const string& description, int total_members)
        : group_id(id), name(name), description(description), total_members(total_members) {}

    void add_member(const string& member) {
        members.push_back(member);
    }

    void update_description(const string& description) {
        this->description = description;
    }

    // Optionally, you might want to add getters for these private members
    // string get_group_id() const { return group_id; }
    // string get_name() const { return name; }
    // string get_description() const { return description; }
    // int get_total_members() const { return total_members; }
    // vector<string> get_members() const { return members; }
};

#endif // GROUP_H
