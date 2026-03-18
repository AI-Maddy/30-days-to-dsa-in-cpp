/*
 * Example 3: Set Uniqueness (Cplusplus STL Mastery)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // set<int> — sorted, unique elements, O(log n) ops
    set<int> s = {5, 3, 8, 1, 3, 5, 9};  // duplicates auto-removed
    cout << "set (sorted, unique): ";
    for (int x : s) cout << x << " "; cout << "\n";

    s.insert(4);  cout << "After insert(4): ";
    for (int x : s) cout << x << " "; cout << "\n";

    s.erase(3);   cout << "After erase(3):  ";
    for (int x : s) cout << x << " "; cout << "\n";

    cout << "count(5): " << s.count(5) << "  count(10): " << s.count(10) << "\n";

    // lower_bound / upper_bound on set
    auto lb = s.lower_bound(5);  // first >= 5
    auto ub = s.upper_bound(5);  // first > 5
    cout << "lower_bound(5)=" << *lb << "  upper_bound(5)=" << *ub << "\n";

    // Deduplicate a vector using set
    vector<int> v = {4, 2, 7, 2, 4, 8, 1, 7};
    set<int> dedup(v.begin(), v.end());
    vector<int> uniq(dedup.begin(), dedup.end());
    cout << "\nDeduplicated: ";
    for (int x : uniq) cout << x << " "; cout << "\n";

    // unordered_set — O(1) average, no ordering
    unordered_set<int> us = {10, 20, 30, 40};
    us.insert(50);
    cout << "\nunordered_set contains 30? " << (us.count(30) ? "yes" : "no") << "\n";

    // Set intersection and union via algorithm
    vector<int> a = {1,2,3,4,5}, b = {3,4,5,6,7};
    vector<int> inter, uni;
    set_intersection(a.begin(),a.end(), b.begin(),b.end(), back_inserter(inter));
    set_union(a.begin(),a.end(), b.begin(),b.end(), back_inserter(uni));
    cout << "\nIntersection: "; for (int x : inter) cout << x << " "; cout << "\n";
    cout << "Union:        "; for (int x : uni)   cout << x << " "; cout << "\n";

    return 0;
}
