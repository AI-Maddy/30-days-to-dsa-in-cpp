/*
 * Example 5: Rotate Array (Prefix Sum plus Difference Array plus Range queries patterns)
 */
#include <bits/stdc++.h>
using namespace std;
// Rotate array left by k positions using 3 reverses — O(n) time O(1) space.
void rotateLeft(vector<int>& a, int k) {
    int n=a.size(); k%=n;
    reverse(a.begin(), a.begin()+k);
    reverse(a.begin()+k, a.end());
    reverse(a.begin(), a.end());
}
// 2D prefix sum
vector<vector<int>> build2D(vector<vector<int>>& mat) {
    int n=mat.size(), m=mat[0].size();
    vector<vector<int>> p(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        p[i][j]=mat[i-1][j-1]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
    return p;
}
int query2D(vector<vector<int>>& p, int r1,int c1,int r2,int c2){
    return p[r2+1][c2+1]-p[r1][c2+1]-p[r2+1][c1]+p[r1][c1];
}
int main() {
    vector<int> v={1,2,3,4,5,6,7}; rotateLeft(v,3);
    cout << "Rotate left by 3: "; for(int x:v) cout<<x<<" "; cout<<"\n";
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    auto p=build2D(mat);
    cout << "2D sum [0,0]->[1,1]: " << query2D(p,0,0,1,1) << "\n"; // 12
    cout << "2D sum [1,1]->[2,2]: " << query2D(p,1,1,2,2) << "\n"; // 28
    return 0;
}
