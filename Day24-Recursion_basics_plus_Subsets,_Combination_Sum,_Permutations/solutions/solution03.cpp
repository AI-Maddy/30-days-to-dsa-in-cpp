/*
 * Solution 3: Permutations
 */
#include <bits/stdc++.h>
using namespace std;
void permute(vector<int>&nums,int start,vector<vector<int>>&res){
    if(start==(int)nums.size()){res.push_back(nums);return;}
    for(int i=start;i<(int)nums.size();i++){
        swap(nums[start],nums[i]);permute(nums,start+1,res);swap(nums[start],nums[i]);
    }
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<int>nums={1,2,3};vector<vector<int>>res;
    permute(nums,0,res);
    for(auto&p:res){for(int x:p)cout<<x<<" ";cout<<"\n";}
}
