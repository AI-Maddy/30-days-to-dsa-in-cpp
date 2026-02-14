/*
 * Exercise 4: STL Programming - Remove Duplicates
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> removeDuplicates(vector<int>& nums) {
        unordered_set<int> seen;
        vector<int> result;
        for (int num : nums) {
            if (seen.find(num) == seen.end()) {
                result.push_back(num);
                seen.insert(num);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4};
    
    vector<int> result = sol.removeDuplicates(nums);
    
    cout << "Result: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    
    return 0;
}
