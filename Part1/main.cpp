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

}
