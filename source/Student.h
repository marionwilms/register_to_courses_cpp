//
// Created on 16/11/18.
//

#ifndef PROJET_UML_STUDENT_H
#define PROJET_UML_STUDENT_H

#pragma once
#include <iostream>
#include <string>
#include "List_course.h"

using namespace std;

class Student {
public:
    Student(); //default constructor

    Student(string st_id, string st_first_name, string st_last_name, string st_login_id, string st_login_psd, int nb); //student constructor

    void show() const; //show information of a student

    //accessor
    string get_id() const { return id; };

    string get_first_name() const { return first_name; };

    string get_last_name() const { return last_name; };

    string get_login_id() const { return login_id; };

    string get_login_psd() const { return login_psd; };

    int get_nbCourses() const {return nbCourse;};

    List_Course get_list_course() const { return myCourses; };

    //mutator

    void inc_nbCourses() { nbCourse ++;};

    void dec_nbCourses() { nbCourse --;};

    void set_list_cours(Course &co) { myCourses.add_Course(co); };



private:
    string id;          //identifiant
    string first_name;
    string last_name;
    string login_id;
    string login_psd;   //password
    int nbCourse;       //number of courses a student has
    List_Course myCourses;      //list of course of the student
};


#endif //PROJET_UML_STUDENT_H
