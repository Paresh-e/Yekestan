#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include "User.h" // Include User.h for inheritance
#include <fstream>
#include <sstream>
#include <iostream>
class Lesson; // Forward declaration

class Student : public User {
public:
    vector<Lesson*> lessons;
    Student(string _id, string password, string name, string family);
    void addLesson(string , string);
};

#endif // STUDENT_H