#ifndef TEACHER_H
#define TEACHER_H

#include "User.h" // Include User.h for inheritance

class Lesson; // Forward declaration

class Teacher : public User {
public:
     Lesson* lessons; // Pointer to Lesson
     void addLesson(string _name, int _cap);
     Teacher(string _id, string password, string name, string family);
};

#endif // TEACHER_H