/*
 * Example 1: Spiral Order (Matrix)
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& m){
    int top=0,bot=m.size()-1,l=0,r=m[0].size()-1; vector<int> res;
    while(top<=bot&&l<=r){
        for(int c=l;c<=r;c++) res.push_back(m[top][c]); top++;
        for(int ro=top;ro<=bot;ro++) res.push_back(m[ro][r]); r--;
        if(top<=bot){for(int c=r;c>=l;c--) res.push_back(m[bot][c]); bot--;}
        if(l<=r){for(int ro=bot;ro>=top;ro--) res.push_back(m[ro][l]); l++;}
    }
    return res;
}
int main(){
    vector<vector<int>> m={{1,2,3},{4,5,6},{7,8,9}};
    for(int x:spiralOrder(m)) cout<<x<<" "; cout<<"\n"; // 1 2 3 6 9 8 7 4 5
    return 0;
}
