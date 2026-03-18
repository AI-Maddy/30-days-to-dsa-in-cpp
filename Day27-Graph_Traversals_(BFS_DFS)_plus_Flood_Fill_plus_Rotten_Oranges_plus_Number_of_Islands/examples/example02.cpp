/*
 * Example 2: Number of Islands
 */
#include <bits/stdc++.h>
using namespace std;
// Example 2: Number of Islands (BFS)
int numIslands(vector<vector<char>>& grid) {
    int r = grid.size(), c = grid[0].size(), count = 0;
    auto bfs = [&](int sr, int sc) {
        queue<pair<int,int>> q; q.push({sr,sc}); grid[sr][sc]='0';
        int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
        while (!q.empty()) {
            auto [x,y] = q.front(); q.pop();
            for (int d=0;d<4;d++) {
                int nx=x+dx[d],ny=y+dy[d];
                if(nx>=0&&nx<r&&ny>=0&&ny<c&&grid[nx][ny]=='1'){grid[nx][ny]='0';q.push({nx,ny});}
            }
        }
    };
    for (int i=0;i<r;i++) for (int j=0;j<c;j++) if(grid[i][j]=='1'){bfs(i,j);count++;}
    return count;
}
int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},{'1','1','0','0','0'},
        {'0','0','1','0','0'},{'0','0','0','1','1'}
    };
    cout << numIslands(grid) << "\n"; // 3
}
