/*
 * Solution 1: Two Sum (1D Arrays – Two Pointers and Sliding Window basics)
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,t; cin>>n>>t;
    vector<int> a(n); for(int&x:a)cin>>x;
    unordered_set<int> seen;
    for(int x:a){ if(seen.count(t-x)){cout<<"YES\n";return 0;} seen.insert(x);}
    cout<<"NO\n"; return 0;
}
