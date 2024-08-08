#include <iostream>
#include <iomanip>
#include "students_data.h"

void StudentData::add_student_data(string name, int marks) {
    students[name] = marks;
}

void StudentData::passed_students_data(int passing_marks) {
    map<string, int>::iterator it;
    for (it = students.begin(); it != students.end(); ++it) {
        if (it->second >= passing_marks) {
            passed_students.push_back(it->first);
        }
    }
}

void StudentData::get_sorted_name_list() {
    vector<string> names;
    for (auto student: students) {
        names.push_back(student.first);
    }
    cout << "Sorted list by names: " << endl;
    sort(names.begin(), names.end());
    for (auto name: names) {
        cout << "##" << name << endl;
    }
}

void StudentData::get_student_details() {
    cout << "Student Details: " << endl;
    for (auto student: students) {
        cout << "[" << student.first << " - " << student.second << "]" << endl;
    } 
}  

void StudentData::get_passed_students() {
    cout << "Passed student names: " << endl;
    for (auto name: passed_students) {
        cout << name << endl;
    }
}