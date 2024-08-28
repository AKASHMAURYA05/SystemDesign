#include <string>
#include <vector>
#include <ctime>
#include "constants.h"

using namespace std;

// Assuming these are defined in constants.h

// Forward declarations
class Member;
class Bounty;
class Comment;
class Answer;
class Photo;

class Search {
public:
    virtual ~Search() = default;
    virtual void search(const string& query) = 0;
};

class Question : public Search {
private:
    string title;
    string description;
    int view_count;
    int vote_count;
    time_t creation_time;
    time_t update_time;
    QuestionStatus status;
    QuestionClosingRemark closing_remark;
    Bounty* bounty;
    Member* asking_member;
    vector<Photo*> photos;
    vector<Comment*> comments;
    vector<Answer*> answers;

public:
    Question(const string& title, const string& description, Bounty* bounty, Member* asking_member)
        : title(title), description(description), view_count(0), vote_count(0),
          status(QuestionStatus::OPEN), closing_remark(QuestionClosingRemark::DUPLICATE),
          bounty(bounty), asking_member(asking_member) {
        time(&creation_time);
        update_time = creation_time;
    }

    void close() {
        // Implementation not provided
    }

    void undelete() {
        // Implementation not provided
    }

    void add_comment(Comment* comment) {
        // Implementation not provided
    }

    void add_bounty(Bounty* bounty) {
        // Implementation not provided
    }

    void search(const string& query) override {
        // Implementation not provided
        // Should return all questions containing the string query in their title or description.
    }
};

class Comment {
private:
    string text;
    time_t creation_time;
    int flag_count;
    int vote_count;
    Member* asking_member;

public:
    Comment(const string& text, Member* member)
        : text(text), flag_count(0), vote_count(0), asking_member(member) {
        time(&creation_time);
    }

    void increment_vote_count() {
        // Implementation not provided
    }
};

class Answer {
private:
    string answer_text;
    bool accepted;
    int vote_count;
    int flag_count;
    time_t creation_time;
    Member* creating_member;
    vector<Photo*> photos;

public:
    Answer(const string& text, Member* member)
        : answer_text(text), accepted(false), vote_count(0), flag_count(0), creating_member(member) {
        time(&creation_time);
    }

    void increment_vote_count() {
        // Implementation not provided
    }
};