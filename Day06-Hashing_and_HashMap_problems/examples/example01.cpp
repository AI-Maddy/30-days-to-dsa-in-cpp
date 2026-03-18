/*
 * Example 1: Two Sum (Hashing)
 */
#include <bits/stdc++.h>
using namespace std;
// Two Sum — O(n) using unordered_map
vector<int> twoSum(vector<int>& n, int t){
    unordered_map<int,int> s; for(int i=0;i<(int)n.size();i++){int c=t-n[i];if(s.count(c))return{s[c],i};s[n[i]]=i;} return{};
}
int main(){
    vector<int> a={2,7,11,15}; auto r=twoSum(a,9);
    cout<<"["<<r[0]<<","<<r[1]<<"]\n"; // [0,1]
    vector<int> b={3,2,4}; auto r2=twoSum(b,6);
    cout<<"["<<r2[0]<<","<<r2[1]<<"]\n"; // [1,2]
    return 0;
}
