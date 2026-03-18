/*
 * Example 2: Set Bit (Bit Manipulation in Cplusplus)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 40;  // 101000
    cout << "Original n=" << n << " (binary: ";
    for(int i=7;i>=0;i--) cout<<((n>>i)&1); cout<<")\n";
    // Set bit i: n | (1 << i)
    int n1 = n | (1<<1);  // set bit 1
    int n2 = n | (1<<2);  // set bit 2
    cout << "Set bit 1: " << n1 << "\n";
    cout << "Set bit 2: " << n2 << "\n";
    // Set multiple bits using mask
    int mask = (1<<0)|(1<<2)|(1<<4);  // bits 0,2,4
    int n3 = n | mask;
    cout << "Set bits 0,2,4: " << n3 << "\n";
    return 0;
}
