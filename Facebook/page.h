#ifndef PAGE_H
#define PAGE_H

#include <string>
#include <vector>
#include "recommendation.h" // Include Recommendation class

using std::string;
using std::vector;

class Page {
private:
    string page_id;
    string name;
    string description;
    string type;
    int total_members;
    vector<Recommendation*> recommendations; // Store pointers to Recommendation objects

public:
    Page(const string& id, const string& name, const string& description, const string& type, int total_members)
        : page_id(id), name(name), description(description), type(type), total_members(total_members) {}

    const vector<Recommendation*>& get_recommendations() const {
        return recommendations;
    }

    void add_recommendation(Recommendation* recommendation) {
        recommendations.push_back(recommendation);
    }
};

#endif // PAGE_H
