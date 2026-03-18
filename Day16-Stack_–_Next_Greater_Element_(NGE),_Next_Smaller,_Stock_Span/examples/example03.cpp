/*
 * Example 3: Stock Span
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int>&prices){
    int n=prices.size(); vector<int> span(n); stack<int> st;
    for(int i=0;i<n;i++){while(!st.empty()&&prices[st.top()]<=prices[i])st.pop();span[i]=st.empty()?i+1:i-st.top();st.push(i);}
    return span;
}
int main(){
    vector<int> p={100,80,60,70,60,75,85};
    for(int x:stockSpan(p)) cout<<x<<" "; cout<<"\n"; // 1 1 1 2 1 4 6
    return 0;
}
