/*
 * Solution 1: Dijkstra SSSP
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int src,int n,vector<vector<pair<int,int>>>&adj){
    vector<int>dist(n,INT_MAX);priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    dist[src]=0;pq.push({0,src});
    while(!pq.empty()){auto[d,u]=pq.top();pq.pop();if(d>dist[u])continue;
        for(auto[v,w]:adj[u])if(dist[u]+w<dist[v]){dist[v]=dist[u]+w;pq.push({dist[v],v});}}
    return dist;
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    int n=5;vector<vector<pair<int,int>>>adj(n);
    adj[0]={{1,4},{2,1}};adj[2]={{1,2},{3,5}};adj[1]={{3,1}};adj[3]={{4,3}};
    auto d=dijkstra(0,n,adj);for(int i=0;i<n;i++)cout<<"dist["<<i<<"]="<<d[i]<<"\n";}
