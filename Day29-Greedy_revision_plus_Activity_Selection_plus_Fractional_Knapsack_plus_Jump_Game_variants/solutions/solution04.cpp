/*
 * Solution 4: Jump Game II
 */
#include <bits/stdc++.h>
using namespace std;
int jump(vector<int>&nums){
    int jumps=0,curEnd=0,far=0,n=nums.size();
    for(int i=0;i<n-1;i++){far=max(far,i+nums[i]);if(i==curEnd){jumps++;curEnd=far;if(curEnd>=n-1)break;}}
    return jumps;
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<int>nums={2,3,1,1,4};cout<<jump(nums)<<"\n";}
