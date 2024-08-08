// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream in_file {};
    ofstream out_file {};
    string line {};
    int line_number {0};
    out_file.open("output_file.txt", ios::trunc | ios::out);
    if (!out_file) {
        cout << "Unable to create output_file.txt" << endl;\
        return 1;
    }

    in_file.open("romeoandjuliet.txt");
    if (!in_file) {
        cout << "Unable to open romeoandjuliet.txt" << endl;
        return 1;
    }

    while (getline(in_file, line)) {
        out_file << ++line_number << " " << line << endl;
    }
    
    return 0;
}

