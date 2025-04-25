//
// Created by asus on 4/25/2025.
//

#include "Teacher.h"
#include "Lesson.h"

void Teacher::addLesson(string _name, int _cap) {
    Lesson(_name,_cap,this);
}
Teacher::Teacher(string _id, string password, string name, string family): User(_id, password, name, family),
                                                                           lessons(nullptr) {
    cout<<" co"<<endl;
}
