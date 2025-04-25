//
// Created by asus on 4/25/2025.
//

#include "User.h"
User::User(string Id, string pass, string name, string family) {
    this->ID = Id;
    this->password = pass;
    this->name = name;
    this->family = family;
}
string User::getFamily() {
    return this->family;
}
string User::getName() {
    return this->name;
}
string User::getPassword() {
    return this->password;
}
string User::getID() {
    return this->ID;
}


