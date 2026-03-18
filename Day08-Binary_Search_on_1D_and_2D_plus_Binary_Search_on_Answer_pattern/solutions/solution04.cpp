/*
 * Solution 4: First and Last Occurrence
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;cin>>n>>k;vector<vector<int>>m(n,vector<int>(n));for(auto&r:m)for(int&x:r)cin>>x;
    int lo=m[0][0],hi=m[n-1][n-1];
    auto count=[&](int mid){int cnt=0,j=n-1;for(int i=0;i<n;i++){while(j>=0&&m[i][j]>mid)j--;cnt+=j+1;}return cnt;};
    while(lo<hi){int mid=lo+(hi-lo)/2;if(count(mid)<k)lo=mid+1;else hi=mid;}
    cout<<lo<<"\n";return 0;
}
