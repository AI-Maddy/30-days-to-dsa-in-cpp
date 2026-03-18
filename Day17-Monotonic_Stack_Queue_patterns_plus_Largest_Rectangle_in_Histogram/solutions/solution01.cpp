/*
 * Solution 1: Valid Parentheses
 */
#include <bits/stdc++.h>
using namespace std;
int main(){string s;cin>>s;stack<char>st;for(char c:s){if(c=='('||c=='['||c=='{')st.push(c);else{if(st.empty()||((c==')'&&st.top()!='(')||(c==']'&&st.top()!='[')||(c=='}'&&st.top()!='{'))) {cout<<"NO\n";return 0;}st.pop();}}cout<<(st.empty()?"YES":"NO")<<"\n";return 0;}
