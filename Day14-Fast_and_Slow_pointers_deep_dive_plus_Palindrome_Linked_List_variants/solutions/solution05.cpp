/*
 * Solution 5: Find Duplicate Number
 */
#include <bits/stdc++.h>
using namespace std;
// Find duplicate in array of n+1 ints in [1,n] using Floyd's cycle detection
int findDuplicate(vector<int>&nums){
    int s=nums[0],f=nums[0];
    do{s=nums[s];f=nums[nums[f]];}while(s!=f);
    s=nums[0];
    while(s!=f){s=nums[s];f=nums[f];}
    return s;
}
int main(){
    vector<int> a={1,3,4,2,2}; cout<<findDuplicate(a)<<"\n"; // 2
    vector<int> b={3,1,3,4,2}; cout<<findDuplicate(b)<<"\n"; // 3
    return 0;
}
