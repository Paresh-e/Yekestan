//
// Created by asus on 4/25/2025.
//

#include "Student.h"

#include "Lesson.h"

vector<string> splitString(const string& str);
class Student;
Student::Student(string _id, string password, string name, string family): User(_id,password,name,family) {

}
void Student::addLesson(string _name , string _ID) {
    fstream file;
    file.open("Lessons_of_student.txt", ios::app);
    if (file.is_open()) {
        file<<this->getID()<<" "<<_name<<" ("<<_ID<<")"<<" 0"<<" 0"<<endl;
    }


    else {
        cout<<"File not found"<<endl;
    }
}

