/*
 * Example 2: Next Smaller Element
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmaller(vector<int>&a){
    int n=a.size(); vector<int> res(n,-1); stack<int> st;
    for(int i=0;i<n;i++){while(!st.empty()&&a[st.top()]>a[i]){res[st.top()]=a[i];st.pop();}st.push(i);}
    return res;
}
int main(){
    vector<int> a={4,2,10,6,1}; for(int x:nextSmaller(a)) cout<<x<<" "; cout<<"\n"; // 2 1 6 1 -1
    return 0;
}
