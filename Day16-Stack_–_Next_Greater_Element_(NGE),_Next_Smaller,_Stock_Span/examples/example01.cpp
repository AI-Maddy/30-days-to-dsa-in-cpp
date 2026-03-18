/*
 * Example 1: Next Greater Element
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreater(vector<int>&a){
    int n=a.size(); vector<int> res(n,-1); stack<int> st;
    for(int i=0;i<n;i++){while(!st.empty()&&a[st.top()]<a[i]){res[st.top()]=a[i];st.pop();}st.push(i);}
    return res;
}
// Circular array NGE
vector<int> nextGreaterCircular(vector<int>&a){
    int n=a.size(); vector<int> res(n,-1); stack<int> st;
    for(int i=2*n-1;i>=0;i--){while(!st.empty()&&a[st.top()]<=a[i%n])st.pop();if(i<n)res[i]=st.empty()?-1:a[st.top()];st.push(i%n);}
    return res;
}
int main(){
    vector<int> a={4,5,2,25}; for(int x:nextGreater(a)) cout<<x<<" "; cout<<"\n"; // 5 25 25 -1
    vector<int> b={1,2,1}; for(int x:nextGreaterCircular(b)) cout<<x<<" "; cout<<"\n"; // 2 -1 2
    return 0;
}
