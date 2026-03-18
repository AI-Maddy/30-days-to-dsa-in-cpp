/*
 * Example 1: Activity Selection
 */
#include <bits/stdc++.h>
using namespace std;
// Example 1: Activity Selection Problem (maximum non-overlapping activities)
int activitySelection(vector<pair<int,int>>& activities) {
    // Sort by end time
    sort(activities.begin(), activities.end(), [](auto& a, auto& b){ return a.second < b.second; });
    int count = 1, lastEnd = activities[0].second;
    for (int i = 1; i < (int)activities.size(); i++) {
        if (activities[i].first >= lastEnd) {
            count++;
            lastEnd = activities[i].second;
        }
    }
    return count;
}
int main() {
    vector<pair<int,int>> acts = {{1,2},{3,4},{0,6},{5,7},{8,9},{5,9}};
    cout << activitySelection(acts) << "\n"; // 4
}
