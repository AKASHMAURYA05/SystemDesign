#ifndef PROFILE_H
#define PROFILE_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Profile {
private:
    string profile_picture;
    string cover_photo;
    string gender;
    
    vector<string> work_experiences; // Assuming work_experience is stored as strings
    vector<string> educations;       // Assuming education is stored as strings
    vector<string> places;           // Assuming places are stored as strings
    vector<string> stats;            // Assuming stats are stored as strings

public:
    Profile(const string& profile_picture, const string& cover_photo, const string& gender)
        : profile_picture(profile_picture), cover_photo(cover_photo), gender(gender) {}

    void add_work_experience(const string& work) {
        work_experiences.push_back(work);
    }

    void add_education(const string& education) {
        educations.push_back(education);
    }

    void add_place(const string& place) {
        places.push_back(place);
    }

    // Optionally, you might want to add getters for these private members
    // string get_profile_picture() const { return profile_picture; }
    // string get_cover_photo() const { return cover_photo; }
    // string get_gender() const { return gender; }
    // vector<string> get_work_experiences() const { return work_experiences; }
    // vector<string> get_educations() const { return educations; }
    // vector<string> get_places() const { return places; }
    // vector<string> get_stats() const { return stats; }
};

#endif // PROFILE_H
