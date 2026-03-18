/*
 * Example 5: Matrix Diagonal Traversal (Matrix)
 */
#include <bits/stdc++.h>
using namespace std;
// Print all diagonals of matrix (top-left to bottom-right)
int main(){
    vector<vector<int>> m={{1,2,3},{4,5,6},{7,8,9}};
    int n=m.size(),k=m[0].size();
    // Group by (i+j): same diagonal has same i+j
    map<int,vector<int>> diag;
    for(int i=0;i<n;i++) for(int j=0;j<k;j++) diag[i+j].push_back(m[i][j]);
    for(auto&[d,v]:diag){for(int x:v) cout<<x<<" "; cout<<"\n";}
    return 0;
}
