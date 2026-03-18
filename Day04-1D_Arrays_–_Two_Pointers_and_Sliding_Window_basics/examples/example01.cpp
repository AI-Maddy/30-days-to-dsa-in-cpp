/*
 * Example 1: Two Sum (1D Arrays – Two Pointers and Sliding Window basics)
 */
// Two Sum on sorted array using two pointers — O(n log n) due to sort, O(n) if pre-sorted.
#include <bits/stdc++.h>
using namespace std;

// Returns indices in the ORIGINAL array that sum to target (hash map approach).
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> seen;
    for (int i = 0; i < (int)nums.size(); i++) {
        int comp = target - nums[i];
        if (seen.count(comp)) return {seen[comp], i};
        seen[nums[i]] = i;
    }
    return {};
}

// Two pointer on sorted array — only works if we just need VALUES, not original indices.
pair<int,int> twoSumSorted(vector<int>& a, int target) {
    int l=0, r=(int)a.size()-1;
    while (l < r) {
        int s = a[l]+a[r];
        if (s==target) return {a[l], a[r]};
        else if (s < target) l++;
        else r--;
    }
    return {-1,-1};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto idx = twoSum(nums, target);
    cout << "Two Sum indices: [" << idx[0] << "," << idx[1] << "]\n"; // [0,1]

    vector<int> sorted = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto [a,b] = twoSumSorted(sorted, 10);
    cout << "Sorted two sum: " << a << "+" << b << "=" << (a+b) << "\n"; // 1+9=10

    // Find ALL pairs summing to target (two pointer)
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    int t = 10;
    int lo=0, hi=(int)arr.size()-1;
    cout << "All pairs summing to " << t << ": ";
    while(lo < hi) {
        if(arr[lo]+arr[hi]==t) { cout<<"("<<arr[lo]<<","<<arr[hi]<<") "; lo++; hi--; }
        else if(arr[lo]+arr[hi]<t) lo++;
        else hi--;
    }
    cout << "\n";

    return 0;
}
