/*
 * Solution 5: Min Stack
 */
#include <bits/stdc++.h>
using namespace std;
int main(){string s;cin>>s;stack<pair<int,string>>st;int k=0;string cur="";for(char c:s){if(isdigit(c))k=k*10+(c-'0');else if(c=='['){st.push({k,cur});k=0;cur="";}else if(c==']'){auto[rk,prev]=st.top();st.pop();string t="";for(int i=0;i<rk;i++)t+=cur;cur=prev+t;}else cur+=c;}cout<<cur<<"\n";return 0;}
