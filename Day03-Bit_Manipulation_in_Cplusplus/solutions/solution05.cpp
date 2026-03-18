/*
 * Solution 5: Count Set Bits (Bit Manipulation in Cplusplus)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    int cnt=0; for(int i=1;i<=n;i++) cnt+=__builtin_popcount(i); cout<<cnt<<"\n";
    return 0;
}
