/*
 * Solution 2: Combination Sum
 */
#include <bits/stdc++.h>
using namespace std;
void combinationSum(vector<int>&cands,int idx,int rem,vector<int>&cur,vector<vector<int>>&res){
    if(rem==0){res.push_back(cur);return;}
    for(int i=idx;i<(int)cands.size();i++){
        if(cands[i]>rem)break;
        cur.push_back(cands[i]);combinationSum(cands,i,rem-cands[i],cur,res);cur.pop_back();
    }
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<int>c={2,3,6,7};sort(c.begin(),c.end());
    vector<vector<int>>res;vector<int>cur;combinationSum(c,0,7,cur,res);
    for(auto&v:res){for(int x:v)cout<<x<<" ";cout<<"\n";}
}
