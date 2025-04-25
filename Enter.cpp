//
//1-menu
//
//
#include <iostream>
using namespace std;
bool login_teacher() {
    cout<<"login_teacher"<<endl;
    return true;
}
bool login_student() {
    cout<<"login_student"<<endl;
    return true;
}
bool signup_teacher() {
    cout<<"signup_teacher"<<endl;
    return true;
}
bool signup_student() {
    cout<<"signup_student"<<endl;
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
                    login_teacher();
                }
                else if(val1==2) {
                    signup_teacher();
                }
                else if(val1==3) {
                    goto back;
                }
            }
        }
        else if(val==2) {
            system("cls");
            cout<<"========Menu========"<<endl;
            cout<<"1. Login"<<endl;
            cout<<"2. Signup"<<endl;
            cout<<"3. Exit"<<endl;
            int val1 = 0;
            while (true) {
                cin>>val1;
                if(val1==1) {
                    login_student();
                }
                else if(val1==2) {
                    signup_student();
                }
                else if(val1==3) {
                    goto back;
                }
            }
        }
        else if(val==3) {

        }
        else if(val==4) {
            system("cls");
            cout<<"Bye!Bye!"<<endl;
            break;
        }
    }


}
int main() {
    menu();
}