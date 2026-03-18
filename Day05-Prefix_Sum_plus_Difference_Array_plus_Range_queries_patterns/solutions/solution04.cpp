/*
 * Solution 4: Difference Array Update (Prefix Sum plus Difference Array plus Range queries patterns)
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n; vector<int> diff(n+1,0);
    int m; cin>>m; while(m--){int l,r,v;cin>>l>>r>>v;diff[l]+=v;if(r+1<=n)diff[r+1]-=v;}
    vector<int> a(n); a[0]=diff[0]; for(int i=1;i<n;i++) a[i]=a[i-1]+diff[i];
    for(int x:a) cout<<x<<" "; cout<<"\n"; return 0;
}
