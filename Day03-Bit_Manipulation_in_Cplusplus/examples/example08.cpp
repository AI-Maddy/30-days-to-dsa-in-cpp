/*
 * Example 8: Working with Vectors and Maps
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> nums = {5, 2, 8, 1, 9, 3};
    
    cout << "Original: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    // Sort using STL
    sort(nums.begin(), nums.end());
    cout << "Sorted: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    // Find element
    auto it = find(nums.begin(), nums.end(), 5);
    if (it != nums.end()) {
        cout << "Found 5 at position " << (it - nums.begin()) << endl;
    }
    
    return 0;
}
