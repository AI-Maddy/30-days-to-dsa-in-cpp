/*
 * Example 4: Toggle Bit (Bit Manipulation in Cplusplus)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 42;  // 101010
    cout << "Original: " << n << "\n";
    // Toggle bit i: n ^ (1 << i)
    int n1 = n ^ (1<<1);  cout << "Toggle bit 1: " << n1 << "\n";
    int n2 = n ^ (1<<3);  cout << "Toggle bit 3: " << n2 << "\n";
    // XOR properties
    int a = 15, b = 9;
    cout << "\nXOR tricks:\n";
    cout << a << " ^ " << a << " = " << (a^a) << " (self-cancel)\n";
    cout << a << " ^ 0 = " << (a^0) << " (identity)\n";
    cout << a << " ^ " << b << " ^ " << a << " = " << (a^b^a) << " (= b)\n";
    // Swap without temp
    int x=5, y=7;
    cout << "Before swap: x=" << x << " y=" << y << "\n";
    x^=y; y^=x; x^=y;
    cout << "After swap:  x=" << x << " y=" << y << "\n";
    return 0;
}
