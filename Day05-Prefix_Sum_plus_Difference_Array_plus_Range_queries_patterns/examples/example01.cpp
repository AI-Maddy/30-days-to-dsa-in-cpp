/*
 * Example 1: Prefix Sum Query (Prefix Sum plus Difference Array plus Range queries patterns)
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> a = {3,1,4,1,5,9,2,6,5,3};
    int n = a.size();
    // Build prefix sum array: pre[i] = a[0]+...+a[i-1]
    vector<int> pre(n+1, 0);
    for (int i=0;i<n;i++) pre[i+1]=pre[i]+a[i];
    // Range sum [l,r] in O(1): pre[r+1] - pre[l]
    cout << "Array: "; for(int x:a) cout<<x<<" "; cout<<"\n";
    cout << "Sum [0,4] = " << pre[5]-pre[0] << "  (expected 14)\n";
    cout << "Sum [2,7] = " << pre[8]-pre[2] << "  (expected 26)\n";
    // Count queries answered in O(1) after O(n) preprocessing
    int Q = 5;
    vector<pair<int,int>> queries = {{0,9},{1,5},{3,6},{0,0},{9,9}};
    for(auto[l,r]:queries)
        cout << "Sum[" << l << "," << r << "] = " << pre[r+1]-pre[l] << "\n";
    return 0;
}
