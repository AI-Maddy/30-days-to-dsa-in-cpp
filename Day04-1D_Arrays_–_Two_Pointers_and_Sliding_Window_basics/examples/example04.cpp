/*
 * Example 4: Longest Substring Without Repeating (1D Arrays – Two Pointers and Sliding Window basics)
 */
// Sliding window + hash map tracking last seen index. O(n) time, O(min(n,alphabet)) space.
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> last;  // char -> last seen index
    int l=0, maxLen=0;
    for (int r=0; r<(int)s.size(); r++) {
        // If char seen and was within window, shrink left
        if (last.count(s[r]) && last[s[r]] >= l)
            l = last[s[r]] + 1;
        last[s[r]] = r;
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}

int main() {
    vector<string> tests = {"abcabcbb","bbbbb","pwwkew",""};
    for (auto& s : tests) {
        cout << """ << s << "" -> " << lengthOfLongestSubstring(s) << "\n";
    }
    // Expected: 3, 1, 3, 0

    // Variant: longest substring with at most k distinct characters
    auto longestKDistinct = [](string s, int k) {
        unordered_map<char,int> freq;
        int l=0, maxLen=0;
        for (int r=0; r<(int)s.size(); r++) {
            freq[s[r]]++;
            while ((int)freq.size() > k) {
                if (--freq[s[l]]==0) freq.erase(s[l]);
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    };
    cout << "\nLongest with at most 2 distinct in \"eceba\": "
         << longestKDistinct("eceba", 2) << "\n";  // 3

    return 0;
}
