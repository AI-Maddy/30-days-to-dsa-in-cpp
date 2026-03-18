/*
 * Solution 1: Vector Sort (Time and Space Complexity plus STL Algorithms)
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> v(n); for(int&x:v) cin>>x;
    sort(v.begin(),v.end()); // ascending
    for(int x:v) cout<<x<<" "; cout<<"\n";
    return 0;
}
