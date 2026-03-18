/*
 * Solution 4: Deque Operations (Time and Space Complexity plus STL Algorithms)
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin>>n;
    vector<int> v(n); iota(v.begin(),v.end(),1);
    int k; cin>>k; rotate(v.begin(),v.begin()+k,v.end());
    for(int x:v) cout<<x<<" "; cout<<"\n";
    return 0;
}
