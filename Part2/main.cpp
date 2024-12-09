#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int sum_ascii(const string &s) {
    int total = 0;
    for (char c : s) {
        total += (int)c;
    }
    return total;
}

int main() {
    ifstream infile("lab-37-data.txt"); 
    if (!infile) {
        cerr << "Error" << endl;
        return 1;
    }

    long long grand_total = 0;
    string code;
    while (infile >> code) {
        grand_total += sum_ascii(code);
    }

    infile.close();

    cout << "Grand total of ASCII sums: " << grand_total << endl;

    return 0;
}
