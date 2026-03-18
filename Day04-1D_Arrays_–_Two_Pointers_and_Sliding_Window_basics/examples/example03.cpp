/*
 * Example 3: Trapping Rain Water (1D Arrays – Two Pointers and Sliding Window basics)
 */
// Two pointer with running max — O(n) time, O(1) space.
#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& h) {
    int n = h.size(), water = 0;
    int l=0, r=n-1, lMax=0, rMax=0;
    while (l < r) {
        if (h[l] < h[r]) {
            lMax = max(lMax, h[l]);
            water += lMax - h[l];
            l++;
        } else {
            rMax = max(rMax, h[r]);
            water += rMax - h[r];
            r--;
        }
    }
    return water;
}

// Alternative: prefix max arrays approach — O(n) time and space (easier to understand)
int trapPrefixMax(vector<int>& h) {
    int n = h.size();
    vector<int> lMax(n), rMax(n);
    lMax[0] = h[0];
    for (int i=1;i<n;i++) lMax[i] = max(lMax[i-1], h[i]);
    rMax[n-1] = h[n-1];
    for (int i=n-2;i>=0;i--) rMax[i] = max(rMax[i+1], h[i]);
    int water = 0;
    for (int i=0;i<n;i++) water += min(lMax[i], rMax[i]) - h[i];
    return water;
}

int main() {
    vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped water (two-pointer): " << trap(h) << "\n";     // 6
    cout << "Trapped water (prefix max):  " << trapPrefixMax(h) << "\n"; // 6

    vector<int> h2 = {4,2,0,3,2,5};
    cout << "Test 2: " << trap(h2) << "\n";  // 9

    return 0;
}
