
#ifndef LESSON_H
#define LESSON_H
#include <string>
#include <vector>
using namespace std;
#include <fstream>
class Teacher; // Forward declaration
class Student; // Forward declaration


class Lesson {
public:
    string name;
    int capcity;
    int number_of_students;
    int number;
    Teacher* teacher;
    vector<Student*> students;
    float average;
    float score;
    Lesson(string _name, int _cap, Teacher* _teach);

};

#endif // LESSON_H