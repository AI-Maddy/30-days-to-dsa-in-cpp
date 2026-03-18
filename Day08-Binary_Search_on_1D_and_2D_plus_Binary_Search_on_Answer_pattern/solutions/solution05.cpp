/*
 * Solution 5: Search in 2D Matrix
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,t;cin>>n>>m>>t;vector<vector<int>>mat(n,vector<int>(m));for(auto&r:mat)for(int&x:r)cin>>x;
    int r=0,c=m-1,cnt=0;
    while(r<n&&c>=0){if(mat[r][c]<=t){cnt+=r+1;c--;}else r++;}
    cout<<cnt<<"\n";return 0;
}
