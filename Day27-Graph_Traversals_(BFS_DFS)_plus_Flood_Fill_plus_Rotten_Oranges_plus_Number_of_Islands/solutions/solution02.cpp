/*
 * Solution 2: Number of Islands
 */
#include <bits/stdc++.h>
using namespace std;
int numIslands(vector<vector<char>>&g){
    int r=g.size(),c=g[0].size(),cnt=0;
    int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
    auto bfs=[&](int sr,int sc){queue<pair<int,int>>q;q.push({sr,sc});g[sr][sc]='0';
        while(!q.empty()){auto[x,y]=q.front();q.pop();for(int d=0;d<4;d++){int nx=x+dx[d],ny=y+dy[d];
            if(nx>=0&&nx<r&&ny>=0&&ny<c&&g[nx][ny]=='1'){g[nx][ny]='0';q.push({nx,ny});}}}};
    for(int i=0;i<r;i++)for(int j=0;j<c;j++)if(g[i][j]=='1'){bfs(i,j);cnt++;}
    return cnt;
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<vector<char>>g={{'1','1','0','0'},{'1','1','0','0'},{'0','0','1','0'},{'0','0','0','1'}};
    cout<<numIslands(g)<<"\n";}
