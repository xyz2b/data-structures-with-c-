#ifndef DATASTRUCT_STUDENT_H
#define DATASTRUCT_STUDENT_H
#include <string>

using namespace std;

class Student {
private:
    string name;
    int score;

public:
    Student(string name, int score): name(name), score(score) {}

    string get_name() const {return name;}
    int get_score() const {return score;}

    bool operator == (const Student& s) {
        if(this == &s)
            return true;
            
        return this->name == s.name;
    }

    bool operator < (const Student& s) {
        return this->score < s.score;
    }

    bool operator > (const Student& s) {
        return this->score > s.score;
    }
};

ostream& operator << (ostream& os, const Student& s) {
    os << "student(name: " << s.get_name() << ", score: " << s.get_score() << ")";
    return os;
}

#endif /* DATASTRUCT_STUDENT_H */