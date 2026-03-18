/*
 * Solution 5: Restore IP Addresses
 */
#include <bits/stdc++.h>
using namespace std;
void restoreIPs(const string&s,int idx,int parts,string cur,vector<string>&res){
    if(parts==4&&idx==(int)s.size()){res.push_back(cur.substr(1));return;}
    if(parts==4||idx==(int)s.size())return;
    for(int len=1;len<=3&&idx+len<=(int)s.size();len++){
        string seg=s.substr(idx,len);
        if(seg.size()>1&&seg[0]=='0')break;
        if(stoi(seg)>255)break;
        restoreIPs(s,idx+len,parts+1,cur+"."+seg,res);
    }
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<string>res;restoreIPs("25525511135",0,0,"",res);
    for(auto&s:res)cout<<s<<"\n";}
