/*
 * Example 2: Next Greater Element Circular
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreater(vector<int>&a){
    int n=a.size();vector<int>res(n,-1);stack<int>st;
    for(int i=0;i<n;i++){while(!st.empty()&&a[st.top()]<a[i]){res[st.top()]=a[i];st.pop();}st.push(i);}
    return res;
}
int main(){
    vector<int> a={2,1,2,4,3}; for(int x:nextGreater(a))cout<<x<<" "; cout<<"\n"; // 4 2 4 -1 -1
    return 0;
}
