/*
 * Example 5: Min Platforms
 */
#include <bits/stdc++.h>
using namespace std;
// Example 5: Minimum number of platforms (trains) required
int minPlatforms(vector<int>& arrival, vector<int>& departure) {
    int n = arrival.size();
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int platforms = 1, maxPlatforms = 1, i = 1, j = 0;
    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) { platforms++; i++; }
        else { platforms--; j++; }
        maxPlatforms = max(maxPlatforms, platforms);
    }
    return maxPlatforms;
}
int main() {
    vector<int> arr = {900,940,950,1100,1500,1800};
    vector<int> dep = {910,1200,1120,1130,1900,2000};
    cout << minPlatforms(arr, dep) << "\n"; // 3
}
