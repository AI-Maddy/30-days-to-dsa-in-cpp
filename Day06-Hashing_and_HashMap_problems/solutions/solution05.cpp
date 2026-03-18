/*
 * Solution 5: Subarray Sum K (Hashing)
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n; vector<int> a(n); for(int&x:a)cin>>x;
    unordered_map<int,int> first; first[0]=-1; int sum=0,ans=0;
    for(int i=0;i<n;i++){sum+=(a[i]==0?-1:1);if(first.count(sum))ans=max(ans,i-first[sum]);else first[sum]=i;}
    cout<<ans<<"\n"; return 0;
}
