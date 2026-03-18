/*
 * Example 3: LRU Cache
 */
#include <bits/stdc++.h>
using namespace std;
class LRUCache{
    int cap; list<pair<int,int>> lst; unordered_map<int,list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int c):cap(c){}
    int get(int k){if(!mp.count(k))return -1;lst.splice(lst.begin(),lst,mp[k]);return mp[k]->second;}
    void put(int k,int v){if(mp.count(k)){mp[k]->second=v;lst.splice(lst.begin(),lst,mp[k]);return;}
        if((int)lst.size()==cap){mp.erase(lst.back().first);lst.pop_back();}
        lst.push_front({k,v});mp[k]=lst.begin();}
};
int main(){
    LRUCache c(2);
    c.put(1,1); c.put(2,2);
    cout<<c.get(1)<<"\n"; // 1
    c.put(3,3);
    cout<<c.get(2)<<"\n"; // -1 (evicted)
    c.put(4,4);
    cout<<c.get(1)<<"\n"; // -1 (evicted)
    cout<<c.get(3)<<"\n"; // 3
    cout<<c.get(4)<<"\n"; // 4
    return 0;
}
