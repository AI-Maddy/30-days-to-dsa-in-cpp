/*
 * Example 5: Course Schedule II
 */
#include <bits/stdc++.h>
using namespace std;
// Example 5: Shortest path in DAG (using topological order)
const int INF = 1e9;
vector<int> shortestPathDAG(int src, int n, vector<vector<pair<int,int>>>& adj) {
    // Step 1: Topological sort
    vector<int> indegree(n,0);
    for (int u=0;u<n;u++) for (auto[v,w]:adj[u]) indegree[v]++;
    queue<int> q; for(int i=0;i<n;i++) if(!indegree[i]) q.push(i);
    vector<int> topo;
    while(!q.empty()){int u=q.front();q.pop();topo.push_back(u);for(auto[v,w]:adj[u])if(!--indegree[v])q.push(v);}
    // Step 2: Relax edges in topological order
    vector<int> dist(n, INF); dist[src] = 0;
    for (int u : topo) {
        if (dist[u] == INF) continue;
        for (auto [v,w] : adj[u]) dist[v] = min(dist[v], dist[u] + w);
    }
    return dist;
}
int main() {
    int n = 6; vector<vector<pair<int,int>>> adj(n);
    adj[0].push_back({1,2}); adj[0].push_back({4,1}); adj[1].push_back({2,3});
    adj[4].push_back({2,2}); adj[4].push_back({5,4}); adj[2].push_back({3,6}); adj[5].push_back({3,1});
    auto dist = shortestPathDAG(0, n, adj);
    for(int i=0;i<n;i++) cout<<"dist["<<i<<"]="<<(dist[i]==INF?-1:dist[i])<<"\n";
}
