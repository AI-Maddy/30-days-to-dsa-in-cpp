/*
 * Example 4: Daily Temperatures
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> dailyTemp(vector<int>&t){
    int n=t.size();vector<int>res(n,0);stack<int>st;
    for(int i=0;i<n;i++){while(!st.empty()&&t[st.top()]<t[i]){res[st.top()]=i-st.top();st.pop();}st.push(i);}
    return res;
}
int main(){
    vector<int> t={73,74,75,71,69,72,76,73}; for(int x:dailyTemp(t))cout<<x<<" "; cout<<"\n"; // 1 1 4 2 1 1 0 0
    return 0;
}
