#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; // number of test cases
    while (t--) {
        int n;
        cin >> n;
        int distinct_values = (n * n) / 4 + 1; // floor(n^2 / 4) + 1
        cout << distinct_values << endl;
    }
    return 0;
}
