#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include "User.h" // Include User.h for inheritance

class Lesson; // Forward declaration

class Student : public User {
public:
    vector<Lesson*> lessons;
    Student(string _id, string password, string name, string family);
};

#endif // STUDENT_H