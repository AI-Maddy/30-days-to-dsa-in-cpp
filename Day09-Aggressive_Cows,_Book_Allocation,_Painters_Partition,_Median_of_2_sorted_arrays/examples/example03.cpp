/*
 * Example 3: Upper Bound (BS Answer)
 */
#include <bits/stdc++.h>
using namespace std;
// Painters Partition: same as book allocation
bool canPaint(vector<int>&b,int t,int k){int cnt=1,cur=0;for(int x:b){if(cur+x>t){cnt++;cur=0;}cur+=x;}return cnt<=k;}
int paintersPartition(vector<int>&b,int k){int lo=*max_element(b.begin(),b.end()),hi=accumulate(b.begin(),b.end(),0),ans=hi;while(lo<=hi){int m=lo+(hi-lo)/2;if(canPaint(b,m,k)){ans=m;hi=m-1;}else lo=m+1;}return ans;}
int main(){
    vector<int> boards={10,20,30,40}; int k=2;
    cout<<paintersPartition(boards,k)<<"\n"; // 60
    return 0;
}
