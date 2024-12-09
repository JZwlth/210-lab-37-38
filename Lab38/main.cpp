#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(const string &s) {
    int total = 0;
    for (char c : s) {
        total += (int)c;
    }
    return total;
}

int main() {
    ifstream infile("lab-37-data.txt");
    if (!infile) {
    }
        map<int, list<string>> hash_table;
    string code;
    while (infile >> code) {
        int hash_index = gen_hash_index(code);
        hash_table[hash_index].push_back(code);
    }
    infile.close();

    bool done = false;
    while (!done) {
        cout << "\nMenu:\n";
        cout << "1. Print the first 100 entries\n";
        cout << "2. Search for a key\n";
        cout << "3. Add a key and code\n";
        cout << "4. Remove a key\n";
        cout << "5. Modify a key\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                print_first_100(hash_table);
                break;
            case 2:
                search_key(hash_table);
                break;
            case 3:
                add_key(hash_table);
                break;
            case 4:
                remove_key(hash_table);
                break;
            case 5:
                modify_key(hash_table);
                break;
            case 6:
                done = true;
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
                break;
        }
    }