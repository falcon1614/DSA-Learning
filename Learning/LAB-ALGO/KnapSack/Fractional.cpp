#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure for an item
struct Item {
    int value, weight;
    
    // Constructor
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator to sort items by value/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to get maximum value in Fractional Knapsack
double fractionalKnapsack(int W, vector<Item> &items) {
    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (auto &item : items) {
        if (W >= item.weight) {
            // Take the full item
            W -= item.weight;
            totalValue += item.value;
        } else {
            // Take fraction of the item
            totalValue += item.value * ((double)W / item.weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<Item> items;
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; ++i) {
        int value, weight;
        cin >> value >> weight;
        items.emplace_back(value, weight);
    }

    double maxValue = fractionalKnapsack(W, items);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
