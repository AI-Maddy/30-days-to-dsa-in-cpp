/*
 * Exercise 3: Set Uniqueness (Cplusplus STL Mastery)
 */
// Problem: Given two arrays A and B, find their intersection and union.
// Output both in sorted order.
//
// Approach:
// 1) Insert both arrays into sets to get unique elements.
// 2) Use set_intersection and set_union (requires sorted input).
// Complexity: O(n log n).
#include <bits/stdc++.h>
using namespace std;

pair<vector<int>,vector<int>> intersectionAndUnion(vector<int> a, vector<int> b) {
    // TODO: compute intersection and union using sets or STL algorithms
    return {};
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    auto [inter, uni] = intersectionAndUnion(a, b);
    cout << "Intersection: "; for (int x : inter) cout << x << " "; cout << "\n";
    cout << "Union:        "; for (int x : uni)   cout << x << " "; cout << "\n";
    return 0;
}
