/*
 * Example 2: Fractional Knapsack
 */
#include <bits/stdc++.h>
using namespace std;
// Example 2: Fractional Knapsack
struct Item { int weight, value; };
double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b){
        return (double)a.value/a.weight > (double)b.value/b.weight;
    });
    double total = 0;
    for (auto& item : items) {
        if (capacity >= item.weight) {
            total += item.value;
            capacity -= item.weight;
        } else {
            total += (double)item.value * capacity / item.weight;
            break;
        }
    }
    return total;
}
int main() {
    vector<Item> items = {{10,60},{20,100},{30,120}};
    cout << fixed << setprecision(2) << fractionalKnapsack(50, items) << "\n"; // 240.00
}
