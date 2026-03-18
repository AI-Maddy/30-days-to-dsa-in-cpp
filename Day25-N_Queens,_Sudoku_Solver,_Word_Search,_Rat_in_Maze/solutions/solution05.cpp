/*
 * Solution 5: Rat in a Maze
 */
#include <bits/stdc++.h>
using namespace std;
int dx[]={1,0,0,-1},dy[]={0,1,-1,0};char dc[]={'D','R','L','U'};
void ratMaze(int x,int y,int n,vector<string>&m,string path,vector<vector<bool>>&vis,vector<string>&res){
    if(x==n-1&&y==n-1){res.push_back(path);return;}
    for(int d=0;d<4;d++){int nx=x+dx[d],ny=y+dy[d];
        if(nx>=0&&nx<n&&ny>=0&&ny<n&&!vis[nx][ny]&&m[nx][ny]=='1'){
            vis[nx][ny]=true;ratMaze(nx,ny,n,m,path+dc[d],vis,res);vis[nx][ny]=false;
        }
    }
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    int n=4;vector<string>m={"1100","1110","0110","0011"};
    vector<vector<bool>>vis(n,vector<bool>(n,false));vis[0][0]=true;
    vector<string>res;ratMaze(0,0,n,m,"",vis,res);
    for(auto&p:res)cout<<p<<"\n";}
