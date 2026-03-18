/*
 * Example 2: Map Frequency (Time and Space Complexity plus STL Algorithms)
 */
// Demonstrates STL algorithms: count_if, find_if, transform, max_element.
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, -2, 3, -4, 5, -6, 7, 8, -9, 10};

    // count_if — O(n), count elements satisfying predicate
    int pos = count_if(v.begin(), v.end(), [](int x){ return x > 0; });
    cout << "Positive count: " << pos << "\n";

    // find_if — O(n), returns iterator to first match
    auto it = find_if(v.begin(), v.end(), [](int x){ return x > 5; });
    if (it != v.end()) cout << "First > 5: " << *it << "\n";

    // max_element / min_element — O(n)
    auto mx = max_element(v.begin(), v.end());
    auto mn = min_element(v.begin(), v.end());
    cout << "Max: " << *mx << "  Min: " << *mn << "\n";

    // transform — O(n), apply function to each element
    vector<int> absv(v.size());
    transform(v.begin(), v.end(), absv.begin(), [](int x){ return abs(x); });
    cout << "Absolute values: "; for(int x:absv) cout<<x<<" "; cout<<"\n";

    // transform with two ranges
    vector<int> a = {1,2,3,4,5}, b = {10,20,30,40,50}, c(5);
    transform(a.begin(),a.end(), b.begin(), c.begin(), plus<int>());
    cout << "Element-wise sum: "; for(int x:c) cout<<x<<" "; cout<<"\n";

    // all_of, any_of, none_of — O(n)
    cout << "all positive? " << all_of(v.begin(),v.end(),[](int x){return x>0;}) << "\n";
    cout << "any negative? " << any_of(v.begin(),v.end(),[](int x){return x<0;}) << "\n";
    cout << "none zero?    " << none_of(v.begin(),v.end(),[](int x){return x==0;}) << "\n";

    return 0;
}
