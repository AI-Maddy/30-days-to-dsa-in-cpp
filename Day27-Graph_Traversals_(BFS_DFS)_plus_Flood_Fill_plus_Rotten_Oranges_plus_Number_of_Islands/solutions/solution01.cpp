/*
 * Solution 1: BFS and DFS
 */
#include <bits/stdc++.h>
using namespace std;
void bfs(int src,vector<vector<int>>&adj,int n){
    vector<bool>vis(n,false);queue<int>q;q.push(src);vis[src]=true;
    while(!q.empty()){int u=q.front();q.pop();cout<<u<<" ";for(int v:adj[u])if(!vis[v]){vis[v]=true;q.push(v);}}cout<<"\n";
}
void dfs(int u,vector<vector<int>>&adj,vector<bool>&vis){
    vis[u]=true;cout<<u<<" ";for(int v:adj[u])if(!vis[v])dfs(v,adj,vis);
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    int n=6;vector<vector<int>>adj(n);
    adj[0]={1,2};adj[1]={0,3};adj[2]={0,4};adj[3]={1,5};adj[4]={2};adj[5]={3};
    bfs(0,adj,n);vector<bool>vis(n,false);dfs(0,adj,vis);cout<<"\n";}
