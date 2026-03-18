/*
 * Solution 3: LIS O(nlogn)
 */
#include <bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int>&nums){
    vector<int>tails;
    for(int x:nums){auto it=lower_bound(tails.begin(),tails.end(),x);if(it==tails.end())tails.push_back(x);else *it=x;}
    return tails.size();
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<int>nums={10,9,2,5,3,7,101,18};cout<<lengthOfLIS(nums)<<"\n";}
