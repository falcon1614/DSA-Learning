#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    double sum = 0;
    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        sum += x;
    }

    double result = sum / n;
    cout.precision(12);
    cout << fixed << result << endl;

    return 0;
}
