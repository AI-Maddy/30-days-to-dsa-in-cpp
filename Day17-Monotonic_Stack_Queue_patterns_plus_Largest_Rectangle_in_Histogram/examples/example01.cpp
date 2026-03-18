/*
 * Example 1: Valid Parentheses
 */
#include <bits/stdc++.h>
using namespace std;
bool isValid(string s){stack<char>st;for(char c:s){if(c=='('||c=='['||c=='{')st.push(c);else{if(st.empty())return false;char t=st.top();st.pop();if((c==')'&&t!='(')||(c==']'&&t!='[')||(c=='}'&&t!='{'))return false;}}return st.empty();}
int main(){
    cout<<isValid("()[]{}")<<"\n"; // 1
    cout<<isValid("(]")<<"\n";     // 0
    cout<<isValid("{[]}")<<"\n";   // 1
    return 0;
}
