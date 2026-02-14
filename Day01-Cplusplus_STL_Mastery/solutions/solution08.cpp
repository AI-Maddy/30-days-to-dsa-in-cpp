/*
 * Solution 8: Find Pairs with Target Sum
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> findPairs(vector<int>& nums, int target) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        vector<pair<int, int>> pairs;
        unordered_set<int> seen;
        
        for (int num : nums) {
            if (seen.count(num)) continue;
            if (numSet.count(target - num)) {
                pairs.push_back({num, target - num});
            }
            seen.insert(num);
        }
        
        return pairs;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 7, -1, 5};
    int target = 6;
    
    auto pairs = sol.findPairs(nums, target);
    
    cout << "Pairs summing to " << target << ":" << endl;
    for (auto p : pairs) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
    
    return 0;
}
