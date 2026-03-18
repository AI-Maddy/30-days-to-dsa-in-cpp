/*
 * Example 1: Vector Sort (Cplusplus STL Mastery)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    cout << "Original: "; for (int x : v) cout << x << " "; cout << "\n";

    // sort() — O(n log n)
    sort(v.begin(), v.end());
    cout << "Ascending: "; for (int x : v) cout << x << " "; cout << "\n";

    // reverse() — O(n)
    reverse(v.begin(), v.end());
    cout << "Descending: "; for (int x : v) cout << x << " "; cout << "\n";

    sort(v.begin(), v.end());  // re-sort for search

    // binary_search — requires sorted range, O(log n)
    cout << "\nbinary_search(7): " << binary_search(v.begin(), v.end(), 7) << "\n";

    // lower_bound — first element >= value
    auto lb = lower_bound(v.begin(), v.end(), 5);
    cout << "lower_bound(5) index: " << (lb - v.begin()) << " value: " << *lb << "\n";

    // upper_bound — first element > value
    auto ub = upper_bound(v.begin(), v.end(), 5);
    cout << "upper_bound(5) index: " << (ub - v.begin()) << " value: " << *ub << "\n";

    // Count occurrences in sorted array
    vector<int> d = {1,2,2,2,3,4,4,5};
    int cnt = upper_bound(d.begin(),d.end(),2) - lower_bound(d.begin(),d.end(),2);
    cout << "\nCount of 2 in {1,2,2,2,3,4,4,5}: " << cnt << "\n";

    // Custom comparator: sort by absolute value
    vector<int> w = {-3, 1, -4, 2, -5};
    sort(w.begin(), w.end(), [](int a, int b){ return abs(a) < abs(b); });
    cout << "Sorted by |val|: "; for (int x : w) cout << x << " "; cout << "\n";

    return 0;
}
