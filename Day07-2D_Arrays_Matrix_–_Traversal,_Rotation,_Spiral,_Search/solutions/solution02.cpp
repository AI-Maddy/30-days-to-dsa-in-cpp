/*
 * Solution 2: Rotate 90 Degrees (Matrix)
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<vector<int>> m(n,vector<int>(n)); for(auto&r:m)for(int&x:r)cin>>x;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) swap(m[i][j]);
    for(auto&r:m){reverse(r.begin(),r.end());for(int x:r)cout<<x<<" ";cout<<"\n";}
    return 0;
}
