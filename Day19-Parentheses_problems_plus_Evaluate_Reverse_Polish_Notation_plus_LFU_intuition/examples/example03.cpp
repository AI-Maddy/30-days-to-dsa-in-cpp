/*
 * Example 3: Stock Span
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int>&p){
    int n=p.size();vector<int>sp(n);stack<int>st;
    for(int i=0;i<n;i++){while(!st.empty()&&p[st.top()]<=p[i])st.pop();sp[i]=st.empty()?i+1:i-st.top();st.push(i);}
    return sp;
}
int main(){
    vector<int> p={7,2,1,2}; for(int x:stockSpan(p))cout<<x<<" "; cout<<"\n"; // 1 1 1 2
    return 0;
}
