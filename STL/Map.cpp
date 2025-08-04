// Key Value Pair
// Key Unique
// Value Duplicate Allowed

// Implement AVL TREE or RED BLACK TREE

#include <bits/stdc++.h>
using namespace std;

int main() {

  map<int, int> mp;
  mp.insert(make_pair(1, 10));
  mp.insert(make_pair(2, 20));
  mp.insert(make_pair(3, 30));
  mp.insert(make_pair(4, 40));
  mp.insert(make_pair(5, 50));
  mp.insert(make_pair(6, 60));
  mp.insert(make_pair(7, 70));
  mp.insert(make_pair(8, 80));
  mp.insert(make_pair(9, 90));
  mp.insert(make_pair(10, 100));
  mp.insert(make_pair(11, 110));

  mp[100] = 1000; // Insert or update key-value pair
  mp[5] = 500; // Update existing key-value pair

  for (auto it = mp.begin(); it != mp.end(); it++){
    cout << it->first << " " << it->second << endl; // Print all key-value pairs in the map
  }

}

// multimap<int, int> mp2;
// mp2.insert(make_pair(1, 10));
// mp2.insert(make_pair(2, 20));
// mp2.insert(make_pair(3, 30));
// mp2.insert(make_pair(4, 40));
// mp2.insert(make_pair(5, 50));
// mp2.insert(make_pair(5, 60)); // Insert duplicate key with different value


