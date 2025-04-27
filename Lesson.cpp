//
// Created by asus on 4/25/2025.
//

#include "Lesson.h"
#include "Teacher.h"
Lesson::Lesson(string _name, int _cap, Teacher* _teach) {
    this->name = _name;
    this->capcity = _cap;
    this->teacher = _teach;
    this->average = 0;
    this->score = 0;
    this->number_of_students = 0;
    srand(time(NULL));
    this->number = rand() % 10000+ 10000;
    fstream file;
    file.open("Lesson.txt",ios::app);
    if (file.is_open()) {
        file<<this->number<<" "<<name<<" "<<this->teacher->getID()<<" "<<this->capcity<<" "<<this->number_of_students<<
            " "<<average<<" "<<score<<endl;
        // for (int i =0;i<this->students.size();i++) {
        //     Student* s = this->students[i];
        //     file<<s->getID()<<",";
        // }
        file.close();

    }else {
        cout<<"Can't open file";
    }
}


