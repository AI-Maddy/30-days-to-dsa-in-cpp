/*
 * Solution 4: Deque Operations (Cplusplus STL Mastery)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMax(vector<int>& nums, int k) {
    deque<int> dq;  // stores indices; front = max in current window
    vector<int> res;
    for (int i = 0; i < (int)nums.size(); i++) {
        while (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) res.push_back(nums[dq.front()]);
    }
    return res;
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int& x : nums) cin >> x;
    for (int x : slidingWindowMax(nums, k)) cout << x << " ";
    cout << "\n";
    return 0;
}
