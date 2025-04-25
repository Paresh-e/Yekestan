//
//1-menu
//
//
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <bits/atomic_base.h>
using namespace std;
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

            // استخراج ID
            if (getline(ss, fileId, ' ')) {
                // استخراج پسورد
                if (getline(ss, filePassword, '|')) {
                    // حذف فاصله‌های اضافی از پسورد
                    filePassword.erase(remove_if(filePassword.begin(), filePassword.end(), ::isspace), filePassword.end());

                    // مقایسه ID و پسورد
                    if (fileId == id && filePassword == password) {
                        file.close();
                        return true; // ورود موفقیت‌آمیز
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
    return true;
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
        file<<Id<<" "<<password<<"|"<<name<<" "<<family<<endl;
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
        file<<Id<<" "<<password<<"|"<<name<<" "<<family<<endl;
        file.close();
    }else {
        cout<<"File could not be opened"<<endl;
        return false;
    }
    cout<<"Your ID:"<<Id<<endl;
    return true;

}
void menu() {
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
                        cout<<"loged"<<endl;
                        return;
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
                        break;
                    }
                }
                else if(val1==2) {
                    if (signup_student()) {
                        break;
                    }
                }
                else if(val1==3) {
                    goto back;
                }
            }
        }
        if(val==3) {
            system("cls");
            cout<<"========Admin========"<<endl;
            break;
        }
        if(val==4) {
            system("cls");
            cout<<"Bye!Bye!"<<endl;
            break;
        }
    }


}






int main() {
    menu();
}