//
// Created by adel on 19/11/18.
//

#ifndef PROJET_UML_LIST_COURSE_H
#define PROJET_UML_LIST_COURSE_H

#pragma once
#include <iostream>
#include <string>
#include "Course.h"
#include <map>

using namespace std;

class List_Course {
public:
    List_Course(); //default constructor

    void add_Course(Course &co);

    friend void lecture_Courses(List_Course &C); //to create a list of all the course in the file Course.txt

    void show() const;

    //accessor

    int get_nb() const { return nb; };

    map<string, Course>  get_list_cours() const { return list_course; }

    //mutator
    void set_nb(int n) { nb = n; };



private:
    map<string, Course> list_course;
    int nb; //number of courses in the list
};

#endif //PROJET_UML_LIST_COURSE_H
