/*
 * Solution 5: Priority Queue Top-K (Time and Space Complexity plus STL Algorithms)
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k; cin>>n>>k;
    vector<int> v(n); for(int&x:v)cin>>x;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int x:v){pq.push(x); if((int)pq.size()>k)pq.pop();}
    cout<<pq.top()<<"\n";
    return 0;
}
