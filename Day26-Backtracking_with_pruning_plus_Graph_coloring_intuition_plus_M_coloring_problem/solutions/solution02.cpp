/*
 * Solution 2: Palindrome Partition
 */
#include <bits/stdc++.h>
using namespace std;
bool isPalin(const string&s,int l,int r){while(l<r)if(s[l++]!=s[r--])return false;return true;}
void partition(const string&s,int st,vector<string>&cur,vector<vector<string>>&res){
    if(st==(int)s.size()){res.push_back(cur);return;}
    for(int e=st;e<(int)s.size();e++){
        if(isPalin(s,st,e)){cur.push_back(s.substr(st,e-st+1));partition(s,e+1,cur,res);cur.pop_back();}
    }
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    string s="aab";vector<vector<string>>res;vector<string>cur;
    partition(s,0,cur,res);for(auto&v:res){for(auto&w:v)cout<<w<<" ";cout<<"\n";}}
