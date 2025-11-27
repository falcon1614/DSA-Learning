#include<bits/stdc++.h>
using namespace std;
void coin(int V,vector<int> & change) {
    vector<int> denominations = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    for (int coin : denominations) {
        while (V >= coin) {
            V -= coin;
            change.push_back(coin);
        }
    }
}
int main() {
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;
    vector<int> change;

    coin(amount,change);

    cout << "Minimum number of coins needed: " << change.size() << endl;
    for (int coin : change) {
        cout << coin << " ";
    }
    cout << endl;
    return 0;
}
