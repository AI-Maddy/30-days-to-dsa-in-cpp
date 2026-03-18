/*
 * Solution 5: RPN Evaluate
 */
#include <bits/stdc++.h>
using namespace std;
int main(){string s;getline(cin,s);stack<long long>st;long long cur=0;char op='+';for(int i=0;i<(int)s.size();i++){if(isdigit(s[i]))cur=cur*10+(s[i]-'0');if((!isdigit(s[i])&&s[i]!=' ')||i==(int)s.size()-1){if(op=='+')st.push(cur);else if(op=='-')st.push(-cur);else if(op=='*'){long long t=st.top();st.pop();st.push(t*cur);}else{long long t=st.top();st.pop();st.push(t/cur);}op=s[i];cur=0;}}long long ans=0;while(!st.empty()){ans+=st.top();st.pop();}cout<<ans<<"\n";return 0;}
