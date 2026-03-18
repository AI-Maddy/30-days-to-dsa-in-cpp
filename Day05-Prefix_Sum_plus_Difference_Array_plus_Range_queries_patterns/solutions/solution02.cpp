/*
 * Solution 2: Kadane Maximum Subarray (Prefix Sum plus Difference Array plus Range queries patterns)
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n; vector<int> a(n); for(int&x:a)cin>>x;
    int maxS=INT_MIN,cur=0;
    for(int x:a){cur+=x;maxS=max(maxS,cur);if(cur<0)cur=0;}
    cout<<maxS<<"\n"; return 0;
}
