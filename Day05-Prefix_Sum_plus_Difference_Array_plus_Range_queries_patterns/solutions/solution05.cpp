/*
 * Solution 5: Rotate Array (Prefix Sum plus Difference Array plus Range queries patterns)
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k; cin>>n>>k; vector<int> a(n); for(int&x:a)cin>>x;
    k%=n; // right rotate by k = left rotate by n-k
    reverse(a.begin(),a.end()-k);
    reverse(a.end()-k,a.end());
    reverse(a.begin(),a.end());
    for(int x:a) cout<<x<<" "; cout<<"\n"; return 0;
}
