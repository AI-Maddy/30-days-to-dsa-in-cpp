/*
 * Solution 5: Combination Sum II
 */
#include <bits/stdc++.h>
using namespace std;
void combinationSum2(vector<int>&cands,int idx,int rem,vector<int>&cur,vector<vector<int>>&res){
    if(rem==0){res.push_back(cur);return;}
    for(int i=idx;i<(int)cands.size();i++){
        if(cands[i]>rem)break;
        if(i>idx&&cands[i]==cands[i-1])continue;
        cur.push_back(cands[i]);combinationSum2(cands,i+1,rem-cands[i],cur,res);cur.pop_back();
    }
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<int>c={10,1,2,7,6,1,5};sort(c.begin(),c.end());
    vector<vector<int>>res;vector<int>cur;combinationSum2(c,0,8,cur,res);
    for(auto&v:res){for(int x:v)cout<<x<<" ";cout<<"\n";}
}
