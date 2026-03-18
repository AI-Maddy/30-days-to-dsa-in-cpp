/*
 * Solution 3: Peak Element
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;cin>>n>>k;vector<int>a(n);for(int&x:a)cin>>x;
    auto ok=[&](int mid){int parts=1,cur=0;for(int x:a){if(cur+x>mid){parts++;cur=0;}cur+=x;}return parts<=k;};
    int lo=*max_element(a.begin(),a.end()),hi=accumulate(a.begin(),a.end(),0);
    while(lo<hi){int m=lo+(hi-lo)/2;if(ok(m))hi=m;else lo=m+1;}
    cout<<lo<<"\n";return 0;
}
