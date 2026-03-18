/*
 * Solution 4: Longest Consecutive (Hashing)
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> A(n),B(n),C(n),D(n);
    for(int&x:A)cin>>x; for(int&x:B)cin>>x; for(int&x:C)cin>>x; for(int&x:D)cin>>x;
    unordered_map<int,int> ab;
    for(int a:A) for(int b:B) ab[a+b]++;
    long long ans=0;
    for(int c:C) for(int d:D) ans+=ab[-(c+d)];
    cout<<ans<<"\n"; return 0;
}
