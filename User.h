#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {
    string ID;
    string password;
    string name;
    string family;
public:
    User(string, string, string, string);
    string getName();
    string getPassword();
    string getFamily();
    string getID();
};

#endif // USER_H