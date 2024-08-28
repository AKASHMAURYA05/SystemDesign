#ifndef RECOMMENDATION_H
#define RECOMMENDATION_H

#include <string>
#include <ctime> // For std::tm

using std::string;

class Recommendation {
private:
    string recommendation_id;
    int rating;
    string description;
    std::tm created_at; // Use std::tm for date representation

public:
    Recommendation(const string& id, int rating, const string& description)
        : recommendation_id(id), rating(rating), description(description) {
        std::time_t now = std::time(nullptr);
        created_at = *std::localtime(&now);
    }

    // Optionally, you might want to add getters for these private members
    // string get_recommendation_id() const { return recommendation_id; }
    // int get_rating() const { return rating; }
    // string get_description() const { return description; }
    // std::tm get_created_at() const { return created_at; }
};

#endif // RECOMMENDATION_H
