// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>

using namespace std;

bool find_substring(const string &word_to_find, const string &target) {
    size_t found = target.find(word_to_find);
    if (found == string::npos)
        return false;
    else
        return true;
}

int main() {
    
    ifstream in_file;
    in_file.open("./romeoandjuliet.txt");

    if (!in_file) {
        cout << "Unable to open the file." << endl;
        return 1;
    }

    int words_cnt {0};
    int match_word_cnt {0};
    string word_to_find {};
    string word_read {};

    cout << "Enter the substring to search for: ";
    cin >> word_to_find;

    while (in_file >> word_read) {
        ++words_cnt;
        if (find_substring(word_to_find, word_read)) {
           ++match_word_cnt;
           cout << word_read << " ";
        }        
    }

    cout << words_cnt << " words were searched..." << endl;
    cout << "The substring " << word_to_find << " was found " << match_word_cnt << " times " << endl;
    
    in_file.close();
    cout << endl;
    return 0;
}

