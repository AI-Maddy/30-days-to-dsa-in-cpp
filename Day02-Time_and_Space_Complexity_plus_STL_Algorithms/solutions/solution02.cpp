/*
 * Solution 2: Map Frequency (Time and Space Complexity plus STL Algorithms)
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> v(n); for(int&x:v) cin>>x;
    cout << accumulate(v.begin(),v.end(),0) << "\n"; // sum
    cout << *max_element(v.begin(),v.end()) << "\n"; // max
    int pos=count_if(v.begin(),v.end(),[](int x){return x>0;});
    cout << pos << "\n";
    return 0;
}
