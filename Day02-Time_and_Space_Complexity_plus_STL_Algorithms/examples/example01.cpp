/*
 * Example 1: Vector Sort (Time and Space Complexity plus STL Algorithms)
 */
// Demonstrates STL sorting variants and their complexity.
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {5,2,8,1,9,3,7,4,6,0};

    // sort — O(n log n), unstable introsort
    vector<int> v1 = v;
    sort(v1.begin(), v1.end());
    cout << "sort (ascending):   "; for(int x:v1) cout<<x<<" "; cout<<"\n";

    // stable_sort — O(n log n), preserves relative order of equal elements
    vector<pair<int,char>> pv = {{3,'a'},{1,'b'},{3,'c'},{2,'d'},{1,'e'}};
    stable_sort(pv.begin(), pv.end(), [](auto&a,auto&b){return a.first<b.first;});
    cout << "stable_sort pairs: ";
    for(auto&[k,c]:pv) cout<<"("<<k<<","<<c<<") "; cout<<"\n";

    // partial_sort — O(n log k), sorts only first k elements
    vector<int> v2 = v;
    partial_sort(v2.begin(), v2.begin()+4, v2.end());
    cout << "partial_sort k=4:   "; for(int x:v2) cout<<x<<" "; cout<<"\n";

    // nth_element — O(n) average, puts correct element at position k
    vector<int> v3 = v;
    nth_element(v3.begin(), v3.begin()+4, v3.end());
    cout << "nth_element(4):     5th smallest = " << v3[4] << "\n";

    // accumulate — O(n), sum using + by default
    int sum = accumulate(v1.begin(), v1.end(), 0);
    cout << "\naccumulate (sum): " << sum << "\n";

    // product using accumulate with custom op
    vector<int> small = {1,2,3,4,5};
    int prod = accumulate(small.begin(), small.end(), 1, multiplies<int>());
    cout << "accumulate (product 1..5): " << prod << "\n";

    return 0;
}
