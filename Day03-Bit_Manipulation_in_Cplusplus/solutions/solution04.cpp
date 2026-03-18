/*
 * Solution 4: Toggle Bit (Bit Manipulation in Cplusplus)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    uint32_t n; cin>>n;
    uint32_t r=0; for(int i=0;i<32;i++){r=(r<<1)|(n&1);n>>=1;} cout<<r<<"\n";
    return 0;
}
