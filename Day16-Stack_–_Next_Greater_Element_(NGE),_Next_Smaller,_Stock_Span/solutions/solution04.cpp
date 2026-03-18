/*
 * Solution 4: Previous Greater Element
 */
#include <bits/stdc++.h>
using namespace std;
int main(){string s;cin>>s;stack<int>st;int score=0;for(char c:s){if(c=='(')st.push(score),score=0;else{score=st.top()+max(score*2,1);st.pop();}}cout<<score<<"\n";return 0;}
