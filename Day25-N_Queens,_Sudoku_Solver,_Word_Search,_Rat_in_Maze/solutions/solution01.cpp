/*
 * Solution 1: N-Queens Board
 */
#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<string>& b, int r, int c, int n){
    for(int i=0;i<r;i++){
        if(b[i][c]=='Q')return false;
        if(c-(r-i)>=0&&b[i][c-(r-i)]=='Q')return false;
        if(c+(r-i)<n&&b[i][c+(r-i)]=='Q')return false;
    }return true;
}
void solve(int row,int n,vector<string>&b,vector<vector<string>>&res){
    if(row==n){res.push_back(b);return;}
    for(int c=0;c<n;c++){if(isSafe(b,row,c,n)){b[row][c]='Q';solve(row+1,n,b,res);b[row][c]='.';}}
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    int n=4;vector<string>b(n,string(n,'.'));vector<vector<string>>res;
    solve(0,n,b,res);cout<<res.size()<<"\n";}
