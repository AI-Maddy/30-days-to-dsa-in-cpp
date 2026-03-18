/*
 * Solution 1: M-Coloring
 */
#include <bits/stdc++.h>
using namespace std;
bool safe(int node,vector<vector<int>>&adj,vector<int>&col,int c){
    for(int nb:adj[node])if(col[nb]==c)return false;return true;
}
bool mColoring(int node,int n,int m,vector<vector<int>>&adj,vector<int>&col){
    if(node==n)return true;
    for(int c=1;c<=m;c++){if(safe(node,adj,col,c)){col[node]=c;if(mColoring(node+1,n,m,adj,col))return true;col[node]=0;}}
    return false;
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    int n=4,m=3;vector<vector<int>>adj(n);
    adj[0]={1,2};adj[1]={0,2,3};adj[2]={0,1,3};adj[3]={1,2};
    vector<int>col(n,0);
    cout<<(mColoring(0,n,m,adj,col)?"Possible":"Not Possible")<<"\n";}
