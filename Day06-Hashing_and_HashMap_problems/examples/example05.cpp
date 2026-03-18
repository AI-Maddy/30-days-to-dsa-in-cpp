/*
 * Example 5: Subarray Sum K (Hashing)
 */
#include <bits/stdc++.h>
using namespace std;
// Subarray Sum = K — prefix sum + hash map O(n)
int subarraySum(vector<int>& nums, int k){
    unordered_map<int,int> cnt; cnt[0]=1; int sum=0,ans=0;
    for(int x:nums){sum+=x; ans+=cnt[sum-k]; cnt[sum]++;}
    return ans;
}
int main(){
    vector<int> a={1,1,1}; cout<<subarraySum(a,2)<<"\n"; // 2
    vector<int> b={1,2,3}; cout<<subarraySum(b,3)<<"\n"; // 2
    return 0;
}
