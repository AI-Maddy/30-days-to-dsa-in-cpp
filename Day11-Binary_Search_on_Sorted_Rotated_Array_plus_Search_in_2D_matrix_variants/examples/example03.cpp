/*
 * Example 3: Search Row-Column Sorted Matrix
 */
#include <bits/stdc++.h>
using namespace std;
bool searchSorted2D(vector<vector<int>>&m,int t){
    int r=0,c=(int)m[0].size()-1;
    while(r<(int)m.size()&&c>=0){if(m[r][c]==t)return true;else if(m[r][c]>t)c--;else r++;}
    return false;
}
int main(){
    vector<vector<int>> m={{1,4,7,11},{2,5,8,12},{3,6,9,16},{10,13,14,17}};
    cout<<searchSorted2D(m,5)<<"\n";  // 1
    cout<<searchSorted2D(m,20)<<"\n"; // 0
    return 0;
}
