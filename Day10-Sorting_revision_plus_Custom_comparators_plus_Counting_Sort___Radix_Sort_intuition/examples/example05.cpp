/*
 * Example 5: Sort by Frequency
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums={1,1,2,2,2,3};
    unordered_map<int,int> freq; for(int x:nums) freq[x]++;
    sort(nums.begin(),nums.end(),[&](int a,int b){return freq[a]!=freq[b]?freq[a]>freq[b]:a<b;});
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for(int x:nums) cout<<x<<" "; cout<<"\n"; // 2 1 3
    return 0;
}
