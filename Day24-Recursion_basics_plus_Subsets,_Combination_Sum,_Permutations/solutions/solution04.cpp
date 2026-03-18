/*
 * Solution 4: Subsets With Duplicates
 */
#include <bits/stdc++.h>
using namespace std;
void subsetsWithDup(vector<int>&nums,int idx,vector<int>&cur,vector<vector<int>>&res){
    res.push_back(cur);
    for(int i=idx;i<(int)nums.size();i++){
        if(i>idx&&nums[i]==nums[i-1])continue;
        cur.push_back(nums[i]);subsetsWithDup(nums,i+1,cur,res);cur.pop_back();
    }
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<int>nums={1,2,2};sort(nums.begin(),nums.end());
    vector<vector<int>>res;vector<int>cur;subsetsWithDup(nums,0,cur,res);
    for(auto&s:res){for(int x:s)cout<<x<<" ";cout<<"\n";}
}
