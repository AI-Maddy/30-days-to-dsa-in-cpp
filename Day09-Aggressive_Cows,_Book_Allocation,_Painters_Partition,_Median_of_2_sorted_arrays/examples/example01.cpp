/*
 * Example 1: Classic Binary Search (BS Answer)
 */
#include <bits/stdc++.h>
using namespace std;
// Aggressive Cows: place k cows in stalls to maximize min distance
bool canPlace(vector<int>&s,int d,int k){int cnt=1,last=s[0];for(int i=1;i<(int)s.size();i++){if(s[i]-last>=d){cnt++;last=s[i];if(cnt>=k)return true;}}return false;}
int aggressiveCows(vector<int>&s,int k){sort(s.begin(),s.end());int lo=1,hi=s.back()-s.front(),ans=0;while(lo<=hi){int m=lo+(hi-lo)/2;if(canPlace(s,m,k)){ans=m;lo=m+1;}else hi=m-1;}return ans;}
int main(){
    vector<int> stalls={1,2,4,8,9};int k=3;
    cout<<aggressiveCows(stalls,k)<<"\n"; // 3
    return 0;
}
