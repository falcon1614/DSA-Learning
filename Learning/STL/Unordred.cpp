#include<bits/stdc++.h>
using namespace std;

// Store unique elements in an unordered set
// It Store in UNordered manner

// Search INsert Erase
// Average Time Complexity: O(1)

// Hashing Function
// Hashing Function is used to map data of arbitrary size to fixed-size values.

int main() {
    // Create an unordered set
    unordered_set<int> us;

    // Insert elements into the unordered set
    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(40);
    us.insert(50);

    //  Check if an element exists in the unordered set
    for(auto it = us.begin(); it!= us.end(); it++){
      cout<<*it<<" "; // Print all elements in the unordered set
    }
}
