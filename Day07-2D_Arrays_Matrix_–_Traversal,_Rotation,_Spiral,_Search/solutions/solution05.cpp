/*
 * Solution 5: Matrix Diagonal Traversal (Matrix)
 */
#include <bits/stdc++.h>
using namespace std;
// Minimum path sum using DP
int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> g(n,vector<int>(m)); for(auto&r:g)for(int&x:r)cin>>x;
    vector<vector<int>> dp=g;
    for(int i=1;i<n;i++) dp[i][0]+=dp[i-1][0];
    for(int j=1;j<m;j++) dp[0][j]+=dp[0][j-1];
    for(int i=1;i<n;i++) for(int j=1;j<m;j++) dp[i][j]+=min(dp[i-1][j],dp[i][j-1]);
    cout<<dp[n-1][m-1]<<"\n"; return 0;
}
