/*
 * Example 4: Rotten Oranges
 */
#include <bits/stdc++.h>
using namespace std;
// Example 4: Rotten Oranges (multi-source BFS)
int orangesRotting(vector<vector<int>>& grid) {
    int r = grid.size(), c = grid[0].size(), fresh = 0, mins = 0;
    queue<pair<int,int>> q;
    for (int i=0;i<r;i++) for (int j=0;j<c;j++) {
        if (grid[i][j]==2) q.push({i,j});
        if (grid[i][j]==1) fresh++;
    }
    if (!fresh) return 0;
    int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
    while (!q.empty()) {
        int sz = q.size(); mins++;
        for (int k=0;k<sz;k++) {
            auto [x,y] = q.front(); q.pop();
            for (int d=0;d<4;d++) {
                int nx=x+dx[d],ny=y+dy[d];
                if(nx>=0&&nx<r&&ny>=0&&ny<c&&grid[nx][ny]==1){grid[nx][ny]=2;fresh--;q.push({nx,ny});}
            }
        }
    }
    return fresh == 0 ? mins - 1 : -1;
}
int main() {
    vector<vector<int>> g = {{2,1,1},{1,1,0},{0,1,1}};
    cout << orangesRotting(g) << "\n"; // 4
}
