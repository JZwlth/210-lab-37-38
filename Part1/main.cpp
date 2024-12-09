#include <iostream>
#include <string>
using namespace std;

int sum_ascii(const string &s) {
    int total = 0;
    for (char c : s) {
        total += (int) c;
    }
    return total;
}

int main() {
    string test_str = "ABC";
    cout << "Testing sum_ascii('ABC'): " << sum_ascii(test_str) << endl;
    // ASCII: 'A' = 65, 'B' = 66, 'C' = 67; sum = 65+66+67 = 198

    return 0;
}
