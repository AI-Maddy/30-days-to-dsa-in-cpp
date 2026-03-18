/*
 * Example 3: Set Uniqueness (Time and Space Complexity plus STL Algorithms)
 */
// Demonstrates set_intersection, set_union, set_difference on sorted ranges.
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1,2,3,4,5,6}, b = {4,5,6,7,8,9};
    // Both must be sorted for set algorithms

    vector<int> inter, uni, diff_ab, diff_ba, sym_diff;
    set_intersection(a.begin(),a.end(), b.begin(),b.end(), back_inserter(inter));
    set_union(a.begin(),a.end(),        b.begin(),b.end(), back_inserter(uni));
    set_difference(a.begin(),a.end(),   b.begin(),b.end(), back_inserter(diff_ab));
    set_difference(b.begin(),b.end(),   a.begin(),a.end(), back_inserter(diff_ba));
    set_symmetric_difference(a.begin(),a.end(), b.begin(),b.end(), back_inserter(sym_diff));

    cout << "A: "; for(int x:a) cout<<x<<" "; cout<<"\n";
    cout << "B: "; for(int x:b) cout<<x<<" "; cout<<"\n";
    cout << "Intersection:        "; for(int x:inter)    cout<<x<<" "; cout<<"\n";
    cout << "Union:               "; for(int x:uni)      cout<<x<<" "; cout<<"\n";
    cout << "Difference (A-B):    "; for(int x:diff_ab)  cout<<x<<" "; cout<<"\n";
    cout << "Difference (B-A):    "; for(int x:diff_ba)  cout<<x<<" "; cout<<"\n";
    cout << "Symmetric difference:"; for(int x:sym_diff) cout<<x<<" "; cout<<"\n";

    // merge two sorted arrays
    vector<int> merged;
    merge(a.begin(),a.end(), b.begin(),b.end(), back_inserter(merged));
    cout << "Merged:              "; for(int x:merged)   cout<<x<<" "; cout<<"\n";

    return 0;
}
