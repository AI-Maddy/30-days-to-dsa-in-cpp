/*
 * Solution 2: Lower Bound (BS Answer)
 */
#include <bits/stdc++.h>
using namespace std;
// Book Allocation: allocate n books to m students, minimize max pages
bool feasible(vector<int>&p,int maxP,int m){int cnt=1,cur=0;for(int x:p){if(cur+x>maxP){cnt++;cur=0;}cur+=x;}return cnt<=m;}
int bookAlloc(vector<int>&p,int m){int lo=*max_element(p.begin(),p.end()),hi=accumulate(p.begin(),p.end(),0),ans=hi;while(lo<=hi){int mid=lo+(hi-lo)/2;if(feasible(p,mid,m)){ans=mid;hi=mid-1;}else lo=mid+1;}return ans;}
int main(){
    vector<int> pages={12,34,67,90};int m=2;
    cout<<bookAlloc(pages,m)<<"\n"; // 113
    return 0;
}
