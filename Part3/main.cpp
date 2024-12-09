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
    ifstream infile("data.txt");
    if (!infile) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }


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

    return 0;
}
