/*
 * Example 3: Search Sorted Matrix (Matrix)
 */
#include <bits/stdc++.h>
using namespace std;
// Search in row-sorted col-sorted matrix: start top-right O(n+m)
bool searchMatrix(vector<vector<int>>& m, int target){
    int r=0,c=(int)m[0].size()-1;
    while(r<(int)m.size()&&c>=0){
        if(m[r][c]==target) return true;
        else if(m[r][c]>target) c--;
        else r++;
    }
    return false;
}
int main(){
    vector<vector<int>> m={{1,4,7,11},{2,5,8,12},{3,6,9,16},{10,13,14,17}};
    cout<<searchMatrix(m,5)<<"\n";  // 1
    cout<<searchMatrix(m,20)<<"\n"; // 0
    return 0;
}
