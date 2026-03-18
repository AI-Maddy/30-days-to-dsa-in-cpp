/*
 * Solution 2: Topological Sort Kahn
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int n,vector<vector<int>>&adj){
    vector<int>indeg(n,0),order;for(int u=0;u<n;u++)for(int v:adj[u])indeg[v]++;
    queue<int>q;for(int i=0;i<n;i++)if(!indeg[i])q.push(i);
    while(!q.empty()){int u=q.front();q.pop();order.push_back(u);for(int v:adj[u])if(!--indeg[v])q.push(v);}
    return order;
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    int n=6;vector<vector<int>>adj(n);adj[5]={2,0};adj[4]={0,1};adj[2]={3};adj[3]={1};
    for(int x:topoSort(n,adj))cout<<x<<" ";cout<<"\n";}
