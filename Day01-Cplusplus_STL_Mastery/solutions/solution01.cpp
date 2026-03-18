/*
 * Solution 1: Vector Sort (Cplusplus STL Mastery)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> sortDescUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    reverse(nums.begin(), nums.end());
    return nums;
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int& x : nums) cin >> x;
    auto res = sortDescUnique(nums);
    for (int x : res) cout << x << " ";
    cout << "\n";
    return 0;
}
