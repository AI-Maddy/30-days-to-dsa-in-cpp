/*
 * Solution 1: Spiral Order (Matrix)
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m)); for(auto&r:mat)for(int&x:r)cin>>x;
    int t=0,b=n-1,l=0,r=m-1;
    while(t<=b&&l<=r){
        for(int c=l;c<=r;c++)cout<<mat[t][c]<<" "; t++;
        for(int ro=t;ro<=b;ro++)cout<<mat[ro][r]<<" "; r--;
        if(t<=b){for(int c=r;c>=l;c--)cout<<mat[b][c]<<" "; b--;}
        if(l<=r){for(int ro=b;ro>=t;ro--)cout<<mat[ro][l]<<" "; l++;}
    }
    cout<<"\n"; return 0;
}
