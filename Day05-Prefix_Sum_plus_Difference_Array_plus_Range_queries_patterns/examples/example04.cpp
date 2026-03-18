/*
 * Example 4: Two Pointers Pair (Prefix Sum plus Difference Array plus Range queries patterns)
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Difference array — supports O(1) range updates, O(n) reconstruction
    int n=8;
    vector<int> diff(n+1,0);
    // Add 3 to range [1,4]
    diff[1]+=3; diff[5]-=3;
    // Add -1 to range [3,6]
    diff[3]+=-1; diff[7]-=-1;
    // Add 2 to range [0,2]
    diff[0]+=2; diff[3]-=2;
    // Reconstruct
    vector<int> a(n);
    a[0]=diff[0];
    for(int i=1;i<n;i++) a[i]=a[i-1]+diff[i];
    cout << "After range updates: "; for(int x:a) cout<<x<<" "; cout<<"\n";
    return 0;
}
