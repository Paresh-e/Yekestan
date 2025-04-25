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
    fstream file;
    file.open("Lesson.txt",ios::app);
    if (file.is_open()) {
        file<<name<<" "<<this->teacher->getID()<<" "<<this->capcity<<" "<<average<<" "<<score<<endl;
        // for (int i =0;i<this->students.size();i++) {
        //     Student* s = this->students[i];
        //     file<<s->getID()<<",";
        // }
        file.close();

    }else {
        cout<<"Can't open file";
    }
}
