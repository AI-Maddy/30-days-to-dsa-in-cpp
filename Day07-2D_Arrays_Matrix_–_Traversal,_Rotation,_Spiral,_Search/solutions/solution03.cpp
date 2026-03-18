/*
 * Solution 3: Search Sorted Matrix (Matrix)
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,t; cin>>n>>m>>t;
    vector<vector<int>> mat(n,vector<int>(m)); for(auto&r:mat)for(int&x:r)cin>>x;
    int r=0,c=m-1;
    while(r<n&&c>=0){if(mat[r][c]==t){cout<<r<<" "<<c<<"\n";return 0;}else if(mat[r][c]>t)c--;else r++;}
    cout<<"-1 -1\n"; return 0;
}
