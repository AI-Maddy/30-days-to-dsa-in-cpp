/*
 * Example 2: Rotate 90 Degrees (Matrix)
 */
#include <bits/stdc++.h>
using namespace std;
// Rotate 90 CW: transpose then reverse each row
void rotate90(vector<vector<int>>& m){
    int n=m.size();
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) swap(m[i][j]);
    for(auto& row:m) reverse(row.begin(),row.end());
}
int main(){
    vector<vector<int>> m={{1,2,3},{4,5,6},{7,8,9}};
    rotate90(m);
    for(auto& row:m){for(int x:row) cout<<x<<" "; cout<<"\n";}
    // 7 4 1 / 8 5 2 / 9 6 3
    return 0;
}
