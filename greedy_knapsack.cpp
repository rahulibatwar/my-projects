#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Item details store karne ke liye structure
struct Item {
    int value;
    int weight;
};

// Custom comparator function: Items ko Value/Weight ratio ke descending order mein sort karne ke liye
bool compareItems(Item a, Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2; // Zyada ratio wala pehle aayega
}

double fractionalKnapsack(int W, vector<Item>& items) {
    // 1. Items ko unke ratio ke basis par sort karein (Greedy Choice)
    sort(items.begin(), items.end(), compareItems);

    double finalValue = 0.0; // Total chori ka maal (profit)

    for (auto item : items) {
        // Agar pura item bag mein aa sakta hai, toh daal do
        if (item.weight <= W) {
            W -= item.weight;
            finalValue += item.value;
        } 
        // Agar bag mein thodi hi jagah bachi hai, toh fraction daalein
        else {
            finalValue += item.value * ((double)W / (double)item.weight);
            break; // Bag full ho gaya!
        }
    }
    return finalValue;
}

int main() {
    cout << "--- DSA Masterclass: Fractional Knapsack (Greedy Approach) ---" << endl << endl;

    int W = 50; // Bag ki maximum capacity
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};

    double maxProfit = fractionalKnapsack(W, items);

    cout << "Maximum Value/Profit we can obtain: RS " << maxProfit << endl;
    cout << "------------------------------------------------------------" << endl;
    return 0;
}