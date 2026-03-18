/*
 * Solution 2: Next Greater Element Circular
 */
#include <bits/stdc++.h>
using namespace std;
int main(){string s;cin>>s;stack<int>st;for(int i=0;i<(int)s.size();i++){if(s[i]=='(')st.push(i);else if(!st.empty())st.pop();else s[i]='*';}while(!st.empty()){s[st.top()]='*';st.pop();}string res;for(char c:s)if(c!='*')res+=c;cout<<res<<"\n";return 0;}
