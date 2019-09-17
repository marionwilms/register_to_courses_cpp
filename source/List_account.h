//
// Created by adel on 16/11/18.
//

#ifndef PROJET_UML_LISTE_ACCOUNT_H
#define PROJET_UML_LISTE_ACCOUNT_H

#pragma once

#include <iostream>
#include <string>
#include "Student.h"

#include <map>


using namespace std;

class List_Account {
public:
    List_Account(); //default constructor : initialise the list with 0 Student

    void add_account(Student &st);      //to add an account

    void friend create_list(List_Account &LA);      //create a list of all the student present in the file Account.txt

    void show() const; //to show the students

    map<string, Student> get_map() const {return list_account;}; //accessor

private:
    map<string, Student> list_account;
    int nb; //number of student
};

#endif //PROJET_UML_LISTE_ACCOUNT_H
