/*
 * Solution 1: Two Sum (Hashing)
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t; cin>>n>>t; vector<int> a(n); for(int&x:a)cin>>x;
    unordered_set<int> s;
    for(int x:a){if(s.count(t-x)){cout<<"YES\n";return 0;}s.insert(x);}
    cout<<"NO\n"; return 0;
}
