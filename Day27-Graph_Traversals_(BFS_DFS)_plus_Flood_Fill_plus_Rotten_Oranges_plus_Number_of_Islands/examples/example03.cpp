/*
 * Example 3: Flood Fill
 */
#include <bits/stdc++.h>
using namespace std;
// Example 3: Flood Fill
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int orig = image[sr][sc];
    if (orig == color) return image;
    int r = image.size(), c = image[0].size();
    int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
    queue<pair<int,int>> q; q.push({sr,sc}); image[sr][sc] = color;
    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        for (int d=0;d<4;d++) {
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>=0&&nx<r&&ny>=0&&ny<c&&image[nx][ny]==orig){image[nx][ny]=color;q.push({nx,ny});}
        }
    }
    return image;
}
int main() {
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    auto res = floodFill(image, 1, 1, 2);
    for (auto& row : res) { for (int x : row) cout << x << " "; cout << "\n"; }
}
