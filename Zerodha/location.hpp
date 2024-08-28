#ifndef LOCATION_H
#define LOCATION_H

#include <string>

using std::string;

class Location {
private:
    string street_address;
    string city;
    string state;
    string zip_code;
    string country;

public:
    Location(const string& street, const string& city, const string& state, const string& zip, const string& country)
        : street_address(street), city(city), state(state), zip_code(zip), country(country) {}

    // Optionally, you might want to add getters for these private members
    // string get_street_address() const { return street_address; }
    // string get_city() const { return city; }
    // string get_state() const { return state; }
    // string get_zip_code() const { return zip_code; }
    // string get_country() const { return country; }
};

#endif // LOCATION_H
