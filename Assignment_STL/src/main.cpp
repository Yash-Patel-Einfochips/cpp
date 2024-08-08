#include <iostream>
#include <string>
#include "students_data.h"

int main() {
    int no_of_student;
    string student_name;
    int student_marks;
    int passing_marks;
    StudentData obj;

    cout << "Enter the no. of students: ";
    cin >> no_of_student;

    for (int i=0; i<no_of_student; i++) {
        cout << "Enter the name and marks: ";
        cin >> student_name >> student_marks;
        obj.add_student_data(student_name, student_marks);
    }

    cout << "Enter passing marks: ";
    cin >> passing_marks;
    obj.passed_students_data(passing_marks);

    obj.get_student_details();
    obj.get_passed_students();
    obj.get_sorted_name_list();

    return 0;
}