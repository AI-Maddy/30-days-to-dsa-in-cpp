/*
 * Solution 2: First Negative in Window
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> firstNegative(vector<int>&a,int k){
    deque<int>dq;vector<int>res;
    for(int i=0;i<(int)a.size();i++){while(!dq.empty()&&dq.front()<i-k+1)dq.pop_front();if(a[i]<0)dq.push_back(i);if(i>=k-1)res.push_back(dq.empty()?0:a[dq.front()]);}
    return res;
}
int main(){
    vector<int> a={12,-1,-7,8,-15,30,16,28}; int k=3;
    for(int x:firstNegative(a,k)) cout<<x<<" "; cout<<"\n"; // -1 -1 -7 -15 -15 0
    return 0;
}
