/*
 * Example 3: Top K Frequent (Hashing)
 */
#include <bits/stdc++.h>
using namespace std;
// Top K Frequent Elements — bucket sort O(n)
vector<int> topKFrequent(vector<int>& nums, int k){
    unordered_map<int,int> freq; for(int x:nums) freq[x]++;
    vector<vector<int>> bucket(nums.size()+1);
    for(auto&[v,c]:freq) bucket[c].push_back(v);
    vector<int> res;
    for(int i=(int)bucket.size()-1;i>=0&&(int)res.size()<k;i--)
        for(int x:bucket[i]) if((int)res.size()<k) res.push_back(x);
    return res;
}
int main(){
    vector<int> nums={1,1,1,2,2,3}; int k=2;
    for(int x:topKFrequent(nums,k)) cout<<x<<" "; cout<<"\n"; // 1 2
    return 0;
}
