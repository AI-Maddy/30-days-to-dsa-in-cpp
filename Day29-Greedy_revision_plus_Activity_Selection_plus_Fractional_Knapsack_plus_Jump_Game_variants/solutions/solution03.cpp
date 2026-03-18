/*
 * Solution 3: Jump Game I
 */
#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int>&nums){
    int maxR=0;
    for(int i=0;i<(int)nums.size();i++){if(i>maxR)return false;maxR=max(maxR,i+nums[i]);}
    return true;
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<int>a={2,3,1,1,4},b={3,2,1,0,4};
    cout<<canJump(a)<<"\n"<<canJump(b)<<"\n";}
