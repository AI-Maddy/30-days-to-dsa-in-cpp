/*
 * Example 3: Clear Bit (Bit Manipulation in Cplusplus)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 63;  // 00111111
    cout << "Original n=" << n << " (binary: ";
    for(int i=7;i>=0;i--) cout<<((n>>i)&1); cout<<")\n";
    // Clear bit i: n & ~(1 << i)
    int n1 = n & ~(1<<0);  // clear bit 0
    int n2 = n & ~(1<<5);  // clear bit 5
    cout << "Clear bit 0: " << n1 << "\n";
    cout << "Clear bit 5: " << n2 << "\n";
    // Clear lowest set bit: n & (n-1)
    cout << "\nn & (n-1) clears lowest set bit:\n";
    int x = 52;  // 110100
    while(x) {
        cout << x << " -> ";
        x &= (x-1);
        cout << x << "\n";
    }
    return 0;
}
