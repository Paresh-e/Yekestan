//
//1-menu
//
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Teacher.h"
using namespace std;
string current_Id ;
bool check_if_the_pass_is_correct(string& str) {
    if (str.length() > 20 || str.length() < 8) {
        return false;
    }
    int numberofdigits = 0;
    int numberofCapalph = 0;
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            numberofdigits++;
        }
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                numberofCapalph++;
            }
        }
    }
    if (numberofdigits == 0 || numberofCapalph == 0) {
        return false;
    }
    return true;
}
bool check_if_Id_correct(string id) {
    if (id.length()<0 || id.length()>7) return false;
    for (int i = 0; i < id.length(); i++) {
        if (id[i]<'0' || id[i]>'9') return false;
    }
    return true;
}
bool authenticate(const std::string& id, const std::string& password, const std::string& filename) {
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string fileId, filePassword;


            if (getline(ss, fileId, ' ')) {

                if (getline(ss, filePassword, ' ')) {
                    filePassword.erase(remove_if(filePassword.begin(), filePassword.end(), ::isspace), filePassword.end());


                    if (fileId == id && filePassword == password) {
                        current_Id = id ;
                        file.close();
                        return true;
                    }
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
    return false; // ورود ناموفق
}


bool login_teacher() {
    system("cls");
    cout<<"========Login========"<<endl;
    string id_e;
    cout<<"Please enter your id: ";
    cin>>id_e;
    if (!check_if_Id_correct(id_e)) {
        return false;
    }//format
    string pass_e;
    cout<<"Please enter your password: ";
    cin>>pass_e;
    if (!check_if_the_pass_is_correct(pass_e)) {
        return false;
    }//format
    if (authenticate(id_e,pass_e,"Login-T.txt")) {
        return true;
    }
    return false;

}
bool login_student() {
    system("cls");
    cout<<"========Login========"<<endl;
    string id_e;
    cout<<"Please enter your id: ";
    cin>>id_e;
    if (!check_if_Id_correct(id_e)) {
        return false;
    }//format
    string pass_e;
    cout<<"Please enter your password: ";
    cin>>pass_e;
    if (!check_if_the_pass_is_correct(pass_e)) {
        return false;
    }//format
    if (authenticate(id_e,pass_e,"Login-S.txt")) {
        return true;
    }
    return false;
}
bool check_if_name_correct(string& str) {
    if (str.length() > 20 || str.length() < 8) {
        return false;
    }
    int cap = 0;
    int digit = 0;
    for (int i = 0;i < str.length();i++) {
        if (isdigit(str[i])) {
            digit++;
        }
        if (isupper(str[i])) {
            cap++;
        }
    }
    if (cap == 0 || digit == 0) {
        return false;
    }
    return true;
}

bool signup_teacher() {
    system("cls");
    cout<<"========Signup========"<<endl;
    string name;
    cout<<"Enter your name:"<<endl;
    cin>>name;

    string family;
    cout<<"Enter your family:"<<endl;
    cin>>family;

    string password;
    cout<<"Enter your password:"<<endl;
    cin>>password;
    if (!check_if_the_pass_is_correct(password)) {
        return false;
    }
    srand(time(NULL));
    int Id = (rand() % 1000000) + 1000000;
    fstream file;
    file.open("Login-T.txt", ios::app);
    if (file.is_open()) {
        file<<Id<<" "<<password<<" "<<name<<" "<<family<<endl;
        file.close();
    }else {
        cout<<"File could not be opened"<<endl;
        return false;
    }
    cout<<"Your ID:"<<Id<<endl;
    return true;
}
bool signup_student() {
    system("cls");
    cout<<"========Signup========"<<endl;
    string name;
    cout<<"Enter your name:"<<endl;
    cin>>name;

    string family;
    cout<<"Enter your family:"<<endl;
    cin>>family;

    string password;
    cout<<"Enter your password:"<<endl;
    cin>>password;
    if (!check_if_the_pass_is_correct(password)) {
        return false;
    }
    srand(time(NULL));
    int Id = (rand() % 100000) + 100000;
    fstream file;
    file.open("Login-S.txt", ios::app);
    if (file.is_open()) {
        file<<Id<<" "<<password<<" "<<name<<" "<<family<<endl;
        file.close();
    }else {
        cout<<"File could not be opened"<<endl;
        return false;
    }
    cout<<"Your ID:"<<Id<<endl;
    return true;

}
vector<string> splitString(const string& str) {
    vector<string> words;
    stringstream ss(str);
    string word;
    while (ss >> word) {
        // cout<<word<<" ";
        words.push_back(word);
    }
    return words;
}

void teacher_menu() {
    fstream file;
    file.open("Login-T.txt", ios::in);
    Teacher * current;
    if (file.is_open()) {
        string line;
        vector<string> all;
        getline(file, line);
        all = splitString(line);
        while (all.at(0)!=current_Id) {
            getline(file, line);
            all = splitString(line);
        }
        if (all.at(0)==current_Id) {
            current = new Teacher(all.at(0),all.at(1),all.at(2),all.at(3));
        }else {
            cout<<"something bad happened"<<endl;
            return;
        }
        file.close();
    }
    else {
        cout<<"file could not be opened"<<endl;
        return;
    }
    back :
    system("cls");
        cout<<"========Teacher Menu======"<<endl;
    cout<<"1. creat a lesson"<<endl;
    cout<<"2. list of my lessons"<<endl;
    cout<<"3. Home works"<<endl;
    cout<<"4. Exit"<<endl;
    int val = 0 ;
    cin>>val;
    if (val == 1) {
        system("cls");
        cout<<"========Teacher Menu -> creating Lesson======"<<endl;
        string name;
        cout<<"Enter Lesson`s name:"<<endl;
        cin>>name;
        int capacity;
        cout<<"Enter Lesson`s capacity:"<<endl;
        cin>>capacity;
        current->addLesson(name,capacity);
        system("cls");
        cout<<"========Teacher Menu -> creating Lesson======"<<endl;
        cout<<"Lesson created"<<endl;
        _sleep(1000);
        goto back;
    }
    if (val == 2) {
        system("cls");
        cout<<"========Teacher Menu======"<<endl;
        cout<<"MyLessons: ";
        fstream file2;
        file2.open("Lesson.txt", ios::in);
        string line1;
        vector<string> all;
        vector<string> temp;
        while (getline(file2, line1)) {
            all = splitString(line1);
            if (all.at(1)==current_Id) {
                temp.push_back(all[0]);
            }
        }
        for (int i = 0;i < temp.size();i++) {
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        file2.close();
        _sleep(4000);
        goto back;
    }
    if (val == 3) {
        system("cls");
        cout<<"Home works"<<endl;
        cout<<"NOT YET "<<endl;
        _sleep(4000);
        goto back;
    }
    goto back;
}
void student_menu() {
    system("cls");
    cout<<"========Student Menu======"<<endl;

}

int menu() {
    back:
    system("cls");
    cout<<"========Menu========"<<endl;
    cout<<"1. Techer"<<endl;
    cout<<"2. Student"<<endl;
    cout<<"3. Admin"<<endl;
    cout<<"4. Exit"<<endl;
    int val = 0 ;
    while (true) {
        cin>>val;
        if(val==1) {
            system("cls");
            cout<<"========Menu========"<<endl;
            cout<<"1. Login"<<endl;
            cout<<"2. Signup"<<endl;
            cout<<"3. Exit"<<endl;
            int val1 = 0;
            while (true) {
                cin>>val1;
                if(val1==1) {
                    if (login_teacher()) {
                        teacher_menu();
                        return 1;
                    }
                    cout<<"wrong"<<endl;
                    _sleep(1000);
                    goto back;
                }
                if(val1==2) {
                    if (signup_teacher()) {
                        system("cls");
                        cout<<"========Signup========"<<endl;
                        cout<<"signed up successfuly"<<endl;
                        goto back;
                    }
                    cout<<"wrong"<<endl;
                    _sleep(1000);
                    goto back;
                }
                goto back;
            }
        }
        if(val==2) {
            system("cls");
            cout<<"========Menu========"<<endl;
            cout<<"1. Login"<<endl;
            cout<<"2. Signup"<<endl;
            cout<<"3. Exit"<<endl;
            int val1 = 0;
            while (true) {
                cin>>val1;
                if(val1==1) {
                    if (login_student()) {

                        student_menu();
                        return 2;
                    }
                    cout<<"wrong"<<endl;
                    _sleep(1000);
                    goto back;
                }
                if(val1==2) {
                    if (signup_student()) {
                        system("cls");
                        cout<<"========Signup========"<<endl;
                        cout<<"signed up successfully"<<endl;
                        _sleep(1000);
                        goto back;
                    }
                    cout<<"wrong"<<endl;
                    _sleep(1000);
                    goto back;

                }
                goto back;
            }
        }
        if(val==3) {
            system("cls");
            cout<<"========Admin========"<<endl;
            string Id;
            string password;
            cout<<"Enter your ID:"<<endl;
            cin>>Id;
            cout<<"Enter your password:"<<endl;
            cin>>password;
            if (Id == "1111" && password == "913") {
                system("cls");
                cout<<"========Admin========"<<endl;
                cout<<"Welcome to admin panel"<<endl;
                return 3;
            }
            break;
        }
        system("cls");
        cout<<"Bye!Bye!"<<endl;
        _sleep(1000);
        return 0;
    }
    return 0;
}
int main() {
    int temp = menu();
}





