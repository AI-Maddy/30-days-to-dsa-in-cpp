/*
 * Example 7: Two Pointers Technique
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 10;
    
    int left = 0, right = arr.size() - 1;
    
    cout << "Finding pairs that sum to " << target << ":" << endl;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            cout << "(" << arr[left] << ", " << arr[right] << ")" << endl;
            left++;
            right--;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    return 0;
}
