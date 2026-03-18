/*
 * Example 5: Search in 2D Matrix
 */
#include <bits/stdc++.h>
using namespace std;
// Rows sorted, row[0] < row+1[0]: treat as flat sorted array
bool searchMat(vector<vector<int>>&m,int t){
    int n=m.size(),k=m[0].size(),l=0,r=n*k-1;
    while(l<=r){int mid=l+(r-l)/2,v=m[mid/k][mid%k];if(v==t)return true;else if(v<t)l=mid+1;else r=mid-1;}
    return false;
}
int main(){
    vector<vector<int>> m={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<searchMat(m,3)<<"\n";  // 1
    cout<<searchMat(m,13)<<"\n"; // 0
    return 0;
}
