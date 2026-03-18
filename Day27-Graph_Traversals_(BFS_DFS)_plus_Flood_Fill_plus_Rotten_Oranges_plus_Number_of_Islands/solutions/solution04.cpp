/*
 * Solution 4: Rotten Oranges
 */
#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>>&g){
    int r=g.size(),c=g[0].size(),fresh=0,mins=0;
    queue<pair<int,int>>q;
    for(int i=0;i<r;i++)for(int j=0;j<c;j++){if(g[i][j]==2)q.push({i,j});if(g[i][j]==1)fresh++;}
    if(!fresh)return 0;
    int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
    while(!q.empty()){int sz=q.size();mins++;for(int k=0;k<sz;k++){auto[x,y]=q.front();q.pop();
        for(int d=0;d<4;d++){int nx=x+dx[d],ny=y+dy[d];
            if(nx>=0&&nx<r&&ny>=0&&ny<c&&g[nx][ny]==1){g[nx][ny]=2;fresh--;q.push({nx,ny});}}}}
    return fresh==0?mins-1:-1;
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<vector<int>>g={{2,1,1},{1,1,0},{0,1,1}};cout<<orangesRotting(g)<<"\n";}
