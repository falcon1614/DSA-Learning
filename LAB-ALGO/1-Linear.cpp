#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, s;
    cout << "Enter size of vector";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter Element For Search" << endl;
    cin >> s;

    // Searching Operation
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == s) {
            cout << "Element Found at Index " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Element Not Found" << endl;
    }

    return 0;
}
