/*
 * Solution 3: Set Uniqueness (Time and Space Complexity plus STL Algorithms)
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m; cin>>n>>m;
    vector<int> a(n),b(m); for(int&x:a)cin>>x; for(int&x:b)cin>>x;
    sort(a.begin(),a.end()); sort(b.begin(),b.end());
    vector<int> inter; set_intersection(a.begin(),a.end(),b.begin(),b.end(),back_inserter(inter));
    for(int x:inter) cout<<x<<" "; cout<<"\n";
    return 0;
}
