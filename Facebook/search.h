#ifndef SEARCH_H
#define SEARCH_H

#include <string>

using std::string;

class Search {
public:
    virtual ~Search() = default;

    virtual void search_member(const string& name) = 0;
    virtual void search_group(const string& name) = 0;
    virtual void search_page(const string& name) = 0;
    virtual void search_post(const string& word) = 0;
};

#endif // SEARCH_H
