/*
 * Example 2: Group Anagrams (Hashing)
 */
#include <bits/stdc++.h>
using namespace std;
// Group Anagrams — sort each string as key
vector<vector<string>> groupAnagrams(vector<string>& strs){
    unordered_map<string,vector<string>> mp;
    for(auto& s:strs){string k=s;sort(k.begin(),k.end());mp[k].push_back(s);}
    vector<vector<string>> res; for(auto&[k,v]:mp) res.push_back(v); return res;
}
int main(){
    vector<string> strs={"eat","tea","tan","ate","nat","bat"};
    for(auto& g:groupAnagrams(strs)){
        for(auto& s:g) cout<<s<<" "; cout<<"\n";
    }
    return 0;
}
