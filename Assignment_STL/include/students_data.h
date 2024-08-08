#include <map>
#include <vector>
#include <list>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class StudentData {
    private: 
        map<string, int> students;
        list<string> sort_by_name;
        vector<string> passed_students;
    public:
        void add_student_data(string, int);
        void passed_students_data(int);
        void get_sorted_name_list();
        void get_student_details();
        void get_passed_students();
};