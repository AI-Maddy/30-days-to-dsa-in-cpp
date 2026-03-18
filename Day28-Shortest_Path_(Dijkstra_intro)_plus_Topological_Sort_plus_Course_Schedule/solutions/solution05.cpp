/*
 * Solution 5: Course Schedule II
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> findOrder(int nc,vector<vector<int>>&pre){
    vector<vector<int>>adj(nc);vector<int>indeg(nc,0);
    for(auto&p:pre){adj[p[1]].push_back(p[0]);indeg[p[0]]++;}
    queue<int>q;for(int i=0;i<nc;i++)if(!indeg[i])q.push(i);
    vector<int>order;while(!q.empty()){int u=q.front();q.pop();order.push_back(u);for(int v:adj[u])if(!--indeg[v])q.push(v);}
    return (int)order.size()==nc?order:vector<int>{};
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    auto order=findOrder(4,{{1,0},{2,0},{3,1},{3,2}});
    for(int x:order)cout<<x<<" ";cout<<"\n";}
