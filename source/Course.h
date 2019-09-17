//
// Created by adel on 19/11/18.
//

#ifndef PROJET_UML_COURSE_H
#define PROJET_UML_COURSE_H

#pragma once

#include <iostream>
#include <string>
using namespace std;

class Course {
public:
    Course(); //default constructor

    Course(string co_id, string co_title, string co_teacher, string co_location);

    void show() const;

    //accessor

    string get_id() const { return Course_ID; };

    string get_Title() const { return Title; };

    string get_Teacher() const { return Teacher; };

    string get_Location() const { return Location; };

    int get_nb() const { return nbStudent;};

    //mutator

    void inc_nb() {nbStudent ++;};

    void dec_nb() {nbStudent --;};

private:
    string Course_ID;
    string Title;
    string Teacher;
    string Location;
    int nbStudent; //number of student in the course
};


#endif //PROJET_UML_COURSE_H
