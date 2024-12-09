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

void print_first_100(const map<int, list<string>> &hash_table) {
    int count = 0;
    for (auto it = hash_table.begin(); it != hash_table.end() && count < 100; ++it) {
        cout << "Hash Index: " << it->first << endl;
        cout << "Codes at this index:" << endl;
        for (const auto &val : it->second) {
            cout << "  " << val << endl;
        }
        cout << "----------------------" << endl;
        count++;
    }
}

void search_key(const map<int, list<string>> &hash_table) {
    cout << "Enter the integer key to search for: ";
    int key;
    cin >> key;
    auto it = hash_table.find(key);
    if (it == hash_table.end()) {
        cout << "Key " << key << " not found." << endl;
    } else {
        cout << "Key " << key << " found. Codes:" << endl;
        for (const auto &val : it->second) {
            cout << "  " << val << endl;
        }
    }
}

void add_key(map<int, list<string>> &hash_table) {
    cout << "Enter the key to add: ";
    int key;
    cin >> key;
    cout << "Enter the code (12-char hex string): ";
    string code;
    cin >> code;
    hash_table[key].push_back(code);
    cout << "Code added under key " << key << "." << endl;
}

void remove_key(map<int, list<string>> &hash_table) {
    cout << "Enter the key to remove: ";
    int key;
    cin >> key;
    auto it = hash_table.find(key);
    if (it == hash_table.end()) {
        cout << "Key " << key << " not found, cannot remove." << endl;
    } else {
        hash_table.erase(it);
        cout << "Key " << key << " has been removed." << endl;
    }
}

void modify_key(map<int, list<string>> &hash_table) {
    cout << "Enter the existing key to modify: ";
    int old_key;
    cin >> old_key;
    cout << "Enter the new key to rename it to: ";
    int new_key;
    cin >> new_key;

    auto it = hash_table.find(old_key);
    if (it == hash_table.end()) {
        cout << "Old key " << old_key << " not found, cannot modify." << endl;
        return;
    }

    for (auto &val : it->second) {
        hash_table[new_key].push_back(val);
    }

    hash_table.erase(it);
    cout << "Key " << old_key << " changed to " << new_key << "." << endl;
}

int main() {
    ifstream infile("lab-37-data.txt");
    if (!infile) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
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

    return 0;
}
