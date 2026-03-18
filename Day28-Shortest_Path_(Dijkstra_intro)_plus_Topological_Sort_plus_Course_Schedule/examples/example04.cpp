/*
 * Example 4: Course Schedule
 */
#include <bits/stdc++.h>
using namespace std;
// Example 4: Course Schedule — can you finish all courses? (cycle detection in directed graph)
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    for (auto& p : prerequisites) { adj[p[1]].push_back(p[0]); indegree[p[0]]++; }
    queue<int> q;
    for (int i=0;i<numCourses;i++) if (indegree[i]==0) q.push(i);
    int count = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop(); count++;
        for (int v : adj[u]) if (--indegree[v]==0) q.push(v);
    }
    return count == numCourses;
}
int main() {
    cout << canFinish(2, {{1,0}}) << "\n";       // 1 (no cycle)
    cout << canFinish(2, {{1,0},{0,1}}) << "\n"; // 0 (cycle)
}
