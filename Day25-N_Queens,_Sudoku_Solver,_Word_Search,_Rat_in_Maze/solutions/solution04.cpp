/*
 * Solution 4: Word Search
 */
#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<char>>&b,const string&w,int i,int j,int k){
    if(k==(int)w.size())return true;
    if(i<0||i>=(int)b.size()||j<0||j>=(int)b[0].size()||b[i][j]!=w[k])return false;
    char tmp=b[i][j];b[i][j]='#';
    bool ok=dfs(b,w,i+1,j,k+1)||dfs(b,w,i-1,j,k+1)||dfs(b,w,i,j+1,k+1)||dfs(b,w,i,j-1,k+1);
    b[i][j]=tmp;return ok;
}
bool wordSearch(vector<vector<char>>&b,const string&w){
    for(int i=0;i<(int)b.size();i++)for(int j=0;j<(int)b[0].size();j++)if(dfs(b,w,i,j,0))return true;
    return false;
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<vector<char>>b={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout<<wordSearch(b,"ABCCED")<<"\n"<<wordSearch(b,"SEE")<<"\n"<<wordSearch(b,"ABCB")<<"\n";}
