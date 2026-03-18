/*
 * Solution 3: Trapping Rain Water (1D Arrays – Two Pointers and Sliding Window basics)
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin>>n;
    vector<int> h(n); for(int&x:h)cin>>x;
    int l=0,r=n-1,lm=0,rm=0,water=0;
    while(l<r){if(h[l]<h[r]){lm=max(lm,h[l]);water+=lm-h[l];l++;}else{rm=max(rm,h[r]);water+=rm-h[r];r--;}}
    cout<<water<<"\n"; return 0;
}
