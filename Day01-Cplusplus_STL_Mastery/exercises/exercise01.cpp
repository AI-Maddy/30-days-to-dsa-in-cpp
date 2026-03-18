/*
 * Exercise 1: Vector Sort (Cplusplus STL Mastery)
 */
// Problem: Given n integers, sort them descending, remove duplicates, print.
// Input: first line n, then n integers.
// Output: sorted unique integers in descending order.
//
// Approach:
// 1) Read n integers into a vector.
// 2) Sort ascending, then use unique() to remove duplicates.
// 3) Erase the tail returned by unique().
// 4) Reverse to get descending order and print.
// Complexity: O(n log n) time, O(1) extra space.
#include <bits/stdc++.h>
using namespace std;

vector<int> sortDescUnique(vector<int>& nums) {
    // TODO: sort ascending, remove duplicates, reverse
    return {};
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int& x : nums) cin >> x;
    auto res = sortDescUnique(nums);
    for (int x : res) cout << x << " ";
    cout << "\n";
    return 0;
}
