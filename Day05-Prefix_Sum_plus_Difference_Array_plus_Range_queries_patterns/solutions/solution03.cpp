/*
 * Solution 3: Subarray Sum K (Prefix Sum plus Difference Array plus Range queries patterns)
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k; cin>>n>>k; vector<int> a(n); for(int&x:a)cin>>x;
    unordered_map<int,int> cnt; cnt[0]=1; int sum=0,ans=0;
    for(int x:a){sum+=x;ans+=cnt[sum-k];cnt[sum]++;}
    cout<<ans<<"\n"; return 0;
}
