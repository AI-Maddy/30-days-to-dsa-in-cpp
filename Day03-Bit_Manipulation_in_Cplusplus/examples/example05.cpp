/*
 * Example 5: Count Set Bits (Bit Manipulation in Cplusplus)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Brian Kernighan: n & (n-1) clears rightmost set bit — O(set_bits)
    auto countBK = [](int n) {
        int cnt=0; while(n){ n&=(n-1); cnt++; } return cnt;
    };
    // Built-in: __builtin_popcount — O(1) on modern hardware
    vector<int> tests = {0,1,7,15,42,255};
    cout << "n       | Brian Kernighan | __builtin_popcount\n";
    for(int x:tests)
        cout << x << "\t| " << countBK(x) << "\t\t\t| " << __builtin_popcount(x) << "\n";
    // Count set bits from 1 to n
    auto totalBits = [](int n) {
        int cnt=0; for(int i=1;i<=n;i++) cnt+=__builtin_popcount(i); return cnt;
    };
    cout << "\nTotal set bits from 1 to 10: " << totalBits(10) << "\n";
    cout << "Total set bits from 1 to 16: " << totalBits(16) << "\n";
    return 0;
}
