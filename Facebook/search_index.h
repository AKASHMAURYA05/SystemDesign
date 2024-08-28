#ifndef SEARCH_INDEX_H
#define SEARCH_INDEX_H

#include "search.h"
#include "member.h" // Include Member class if needed
#include "group.h"  // Include Group class if needed
#include "page.h"   // Include Page class if needed
#include "post.h"   // Include Post class if needed

#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class SearchIndex : public Search {
private:
    unordered_map<string, Member*> member_names; // Assuming Member class has get_name() method
    unordered_map<string, Group*> group_names;   // Assuming Group class has get_name() method
    unordered_map<string, Page*> page_titles;    // Assuming Page class has get_name() method
    unordered_map<string, Post*> posts;          // Assuming Post class has get_text() method

public:
    SearchIndex() = default;

    void add_member(Member* member) {
        string name = member->get_name(); // Assuming get_name() returns the member's name
        member_names[name] = member;
    }

    void add_group(Group* group) {
        string name = group->get_name(); // Assuming get_name() returns the group's name
        group_names[name] = group;
    }

    void add_page(Page* page) {
        string title = page->get_title(); // Assuming get_title() returns the page's title
        page_titles[title] = page;
    }

    void add_post(Post* post) {
        string text = post->get_text(); // Assuming get_text() returns the post's text
        posts[text] = post;
    }

    Member* search_member(const string& name) override {
        auto it = member_names.find(name);
        return (it != member_names.end()) ? it->second : nullptr;
    }

    Group* search_group(const string& name) override {
        auto it = group_names.find(name);
        return (it != group_names.end()) ? it->second : nullptr;
    }

    Page* search_page(const string& name) override {
        auto it = page_titles.find(name);
        return (it != page_titles.end()) ? it->second : nullptr;
    }

    Post* search_post(const string& word) override {
        auto it = posts.find(word);
        return (it != posts.end()) ? it->second : nullptr;
    }
};

#endif // SEARCH_INDEX_H
