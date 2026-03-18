/*
 * Solution 4: Course Schedule
 */
#include <bits/stdc++.h>
using namespace std;
bool canFinish(int nc,vector<vector<int>>&pre){
    vector<vector<int>>adj(nc);vector<int>indeg(nc,0);
    for(auto&p:pre){adj[p[1]].push_back(p[0]);indeg[p[0]]++;}
    queue<int>q;for(int i=0;i<nc;i++)if(!indeg[i])q.push(i);
    int cnt=0;while(!q.empty()){int u=q.front();q.pop();cnt++;for(int v:adj[u])if(!--indeg[v])q.push(v);}
    return cnt==nc;
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    cout<<canFinish(2,{{1,0}})<<"\n"<<canFinish(2,{{1,0},{0,1}})<<"\n";}
