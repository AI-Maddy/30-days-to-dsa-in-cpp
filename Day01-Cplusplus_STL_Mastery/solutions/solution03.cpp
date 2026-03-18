/*
 * Solution 3: Set Uniqueness (Cplusplus STL Mastery)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    set<int> sa(a.begin(), a.end()), sb(b.begin(), b.end());
    vector<int> inter, uni;
    set_intersection(sa.begin(),sa.end(), sb.begin(),sb.end(), back_inserter(inter));
    set_union(sa.begin(),sa.end(), sb.begin(),sb.end(), back_inserter(uni));

    cout << "Intersection: "; for (int x : inter) cout << x << " "; cout << "\n";
    cout << "Union:        "; for (int x : uni)   cout << x << " "; cout << "\n";
    return 0;
}
