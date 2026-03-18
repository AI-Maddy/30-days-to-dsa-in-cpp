/*
 * Solution 3: Flood Fill
 */
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> floodFill(vector<vector<int>>&img,int sr,int sc,int color){
    int orig=img[sr][sc];if(orig==color)return img;
    int r=img.size(),c=img[0].size();int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
    queue<pair<int,int>>q;q.push({sr,sc});img[sr][sc]=color;
    while(!q.empty()){auto[x,y]=q.front();q.pop();for(int d=0;d<4;d++){int nx=x+dx[d],ny=y+dy[d];
        if(nx>=0&&nx<r&&ny>=0&&ny<c&&img[nx][ny]==orig){img[nx][ny]=color;q.push({nx,ny});}}}
    return img;
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<vector<int>>img={{1,1,1},{1,1,0},{1,0,1}};
    auto res=floodFill(img,1,1,2);
    for(auto&row:res){for(int x:row)cout<<x<<" ";cout<<"\n";}}
