/*
 * Example 4: Previous Greater Element
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> prevGreater(vector<int>&a){
    int n=a.size(); vector<int> res(n,-1); stack<int> st;
    for(int i=0;i<n;i++){while(!st.empty()&&a[st.top()]<=a[i])st.pop();if(!st.empty())res[i]=a[st.top()];st.push(i);}
    return res;
}
int main(){
    vector<int> a={10,4,5,90,120,80};
    for(int x:prevGreater(a)) cout<<x<<" "; cout<<"\n"; // -1 10 10 -1 -1 120
    return 0;
}
