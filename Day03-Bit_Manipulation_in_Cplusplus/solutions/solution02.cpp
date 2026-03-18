/*
 * Solution 2: Set Bit (Bit Manipulation in Cplusplus)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n; vector<int> a(n); for(int&x:a)cin>>x;
    int res=0; for(int x:a)res^=x; cout<<res<<"\n";
    return 0;
}
