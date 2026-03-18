/*
 * Solution 4: Set Matrix Zeros (Matrix)
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m)); for(auto&r:mat)for(int&x:r)cin>>x;
    bool r0=false,c0=false;
    for(int j=0;j<m;j++) if(mat[0][j]==0) r0=true;
    for(int i=0;i<n;i++) if(mat[i][0]==0) c0=true;
    for(int i=1;i<n;i++) for(int j=1;j<m;j++) if(mat[i][j]==0){mat[i][0]=0;mat[0][j]=0;}
    for(int i=1;i<n;i++) for(int j=1;j<m;j++) if(!mat[i][0]||!mat[0][j]) mat[i][j]=0;
    if(r0) for(int j=0;j<m;j++) mat[0][j]=0;
    if(c0) for(int i=0;i<n;i++) mat[i][0]=0;
    for(auto&r:mat){for(int x:r)cout<<x<<" ";cout<<"\n";}
    return 0;
}
