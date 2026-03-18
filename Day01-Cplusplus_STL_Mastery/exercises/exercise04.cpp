/*
 * Exercise 4: Deque Operations (Cplusplus STL Mastery)
 */
// Problem: Given array and window size k, find maximum in each sliding window.
// Output: n-k+1 maximums.
//
// Hint: Use a monotonic deque that stores indices.
//   - Pop front when index < i-k+1 (out of window).
//   - Pop back when nums[back] <= nums[i] (useless smaller elements).
//   - Front of deque = index of max in current window.
// Complexity: O(n) time.
#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMax(vector<int>& nums, int k) {
    // TODO: implement using monotonic deque
    return {};
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int& x : nums) cin >> x;
    auto res = slidingWindowMax(nums, k);
    for (int x : res) cout << x << " ";
    cout << "\n";
    return 0;
}
