/*
 * Example 4: Longest Consecutive (Hashing)
 */
#include <bits/stdc++.h>
using namespace std;
// Longest Consecutive Sequence — O(n) using unordered_set
int longestConsecutive(vector<int>& nums){
    unordered_set<int> s(nums.begin(),nums.end());
    int best=0;
    for(int x:s){ if(!s.count(x-1)){ int cur=x,len=1; while(s.count(cur+1)){cur++;len++;} best=max(best,len);} }
    return best;
}
int main(){
    vector<int> a={100,4,200,1,3,2}; cout<<longestConsecutive(a)<<"\n"; // 4
    vector<int> b={0,3,7,2,5,8,4,6,0,1}; cout<<longestConsecutive(b)<<"\n"; // 9
    return 0;
}
