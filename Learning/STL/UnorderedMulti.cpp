#include<bits/stdc++.h>
using namespace std;

// Store unique elements in an unordered set
// It Store in UNordered manner

// Search INsert Erase
// Average Time Complexity: O(1)

// Hashing Function
// Hashing Function is used to map data of arbitrary size to fixed-size values.

int main() {
    // Create an unordered multiset
    unordered_multiset<int> us;

    // Insert elements into the unordered multiset
    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(40);
    us.insert(50);
    us.insert(20); // Inserting duplicate element
    us.insert(30); // Inserting duplicate element

    //  Check if an element exists in the unordered multiset
    for(auto it = us.begin(); it!= us.end(); it++){
      cout<<*it<<" "; // Print all elements in the unordered multiset
    }
}

// set, multiset, unordered_set, unordered_multiset

// set: Stores unique elements in sorted order.
// multiset: Allows duplicate elements, stored in sorted order.
// unordered_set: Stores unique elements in an unordered manner, average time complexity O(1)
// unordered_multiset: Allows duplicate elements, stored in an unordered manner, average time complexity O(1)

