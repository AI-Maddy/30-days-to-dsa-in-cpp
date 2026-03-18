/*
 * Solution 5: Cycle Detection BFS
 */
#include <bits/stdc++.h>
using namespace std;
bool hasCycle(int n,vector<vector<int>>&adj){
    vector<bool>vis(n,false);
    for(int src=0;src<n;src++){if(vis[src])continue;
        queue<pair<int,int>>q;q.push({src,-1});vis[src]=true;
        while(!q.empty()){auto[u,par]=q.front();q.pop();
            for(int v:adj[u]){if(!vis[v]){vis[v]=true;q.push({v,u});}else if(v!=par)return true;}}}
    return false;
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    int n=5;vector<vector<int>>adj(n);
    adj[0]={1};adj[1]={0,2,4};adj[2]={1,3};adj[3]={2,4};adj[4]={1,3};
    cout<<(hasCycle(n,adj)?"Cycle":"No cycle")<<"\n";}
