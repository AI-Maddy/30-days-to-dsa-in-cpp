/*
 * Example 2: Container With Most Water (1D Arrays – Two Pointers and Sliding Window basics)
 */
// Two pointer approach: always move the shorter bar inward. O(n) time O(1) space.
#include <bits/stdc++.h>
using namespace std;

int maxWater(vector<int>& h) {
    int l=0, r=(int)h.size()-1, maxArea=0;
    while (l < r) {
        int area = min(h[l], h[r]) * (r - l);
        maxArea = max(maxArea, area);
        // Move the shorter bar — it can only decrease area if we keep it
        if (h[l] < h[r]) l++;
        else r--;
    }
    return maxArea;
}

int main() {
    vector<int> h = {1,8,6,2,5,4,8,3,7};
    cout << "Max water: " << maxWater(h) << "\n";  // 49

    // Trace for small example
    vector<int> small = {1,3,2,5,2,3,4,2,1};
    cout << "Max water (small): " << maxWater(small) << "\n";

    return 0;
}
