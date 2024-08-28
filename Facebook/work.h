#ifndef WORK_H
#define WORK_H

#include <string>

using std::string;

class Work {
private:
    string title;
    string company;
    string location;
    string date_from; // Use string for dates, or std::tm for more detailed date handling
    string date_to;   // Same as above
    string description;

public:
    Work(const string& title, const string& company, const string& location, const string& date_from, const string& date_to, const string& description)
        : title(title), company(company), location(location), date_from(date_from), date_to(date_to), description(description) {}

    // Optionally, you might want to add getters for these private members
    // string get_title() const { return title; }
    // string get_company() const { return company; }
    // string get_location() const { return location; }
    // string get_date_from() const { return date_from; }
    // string get_date_to() const { return date_to; }
    // string get_description() const { return description; }
};

#endif // WORK_H
