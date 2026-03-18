/*
 * Solution 1: Sliding Window Maximum
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> slidingMax(vector<int>&a,int k){
    deque<int>dq;vector<int>res;
    for(int i=0;i<(int)a.size();i++){while(!dq.empty()&&dq.front()<i-k+1)dq.pop_front();while(!dq.empty()&&a[dq.back()]<=a[i])dq.pop_back();dq.push_back(i);if(i>=k-1)res.push_back(a[dq.front()]);}
    return res;
}
int main(){
    vector<int> a={1,3,-1,-3,5,3,6,7}; int k=3;
    for(int x:slidingMax(a,k)) cout<<x<<" "; cout<<"\n"; // 3 3 5 5 6 7
    return 0;
}
