/*
 * Solution 4: Daily Temperatures
 */
#include <bits/stdc++.h>
using namespace std;
// LFU Cache
class LFUCache{
    int cap,minFreq; unordered_map<int,pair<int,int>>kv; unordered_map<int,list<int>>flist; unordered_map<int,list<int>::iterator>pos; unordered_map<int,int>freq;
public:
    LFUCache(int c):cap(c),minFreq(0){}
    void touch(int k){int f=freq[k];freq[k]++;flist[f].erase(pos[k]);if(flist[f].empty()&&f==minFreq)minFreq++;flist[f+1].push_front(k);pos[k]=flist[f+1].begin();}
    int get(int k){if(!kv.count(k))return -1;touch(k);return kv[k].second;}
    void put(int k,int v){if(!cap)return;if(kv.count(k)){kv[k].second=v;touch(k);return;}if((int)kv.size()==cap){int ev=flist[minFreq].back();flist[minFreq].pop_back();kv.erase(ev);pos.erase(ev);freq.erase(ev);}kv[k]={0,v};freq[k]=1;flist[1].push_front(k);pos[k]=flist[1].begin();minFreq=1;}
};
int main(){LFUCache c(2);c.put(1,1);c.put(2,2);cout<<c.get(1)<<"\n";c.put(3,3);cout<<c.get(2)<<"\n";cout<<c.get(3)<<"\n";return 0;}
