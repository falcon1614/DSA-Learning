/*


*/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, x;
        cin >> n >> x;

        if (n == 1) {
            if (x == 0)
                cout << -1 << endl;
            else
                cout << x << endl;
        }
        else if (n == 2) {
            if (x == 0)
                cout << -1 << endl;
            else
                cout << x + 2 << endl;
        }
        else {
            cout << x + n - (n % 2 == 0 ? 0 : 1) << endl;
        }
    }

    return 0;
}
