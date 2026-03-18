/*
 * Example 1: Check Bit (Bit Manipulation in Cplusplus)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 42;  // binary: 101010
    cout << "n = " << n << " (binary: ";
    for(int i=7;i>=0;i--) cout<<((n>>i)&1);
    cout << ")\n";
    for(int i=0;i<8;i++) {
        bool set = (n>>i)&1;
        cout << "bit " << i << ": " << set << "\n";
    }
    // Check specific bit using & with mask
    int mask = 1<<5;  // bit 5
    cout << "\nBit 5 set? " << ((n & mask) != 0) << "\n";
    cout << "Bit 3 set? " << ((n & (1<<3)) != 0) << "\n";
    return 0;
}
