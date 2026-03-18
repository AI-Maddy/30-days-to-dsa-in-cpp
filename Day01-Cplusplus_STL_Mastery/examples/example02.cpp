/*
 * Example 2: Map Frequency (Cplusplus STL Mastery)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    // Build frequency map — O(n log n) for map, O(n) for unordered_map
    map<int,int> freq;
    for (int x : nums) freq[x]++;

    cout << "Frequencies (sorted):\n";
    for (auto& [val, cnt] : freq)
        cout << "  " << val << " -> " << cnt << "\n";

    // Find element with maximum frequency
    auto maxIt = max_element(freq.begin(), freq.end(),
        [](const auto& a, const auto& b){ return a.second < b.second; });
    cout << "\nMost frequent: " << maxIt->first
         << " (appears " << maxIt->second << " times)\n";

    // unordered_map — O(1) average operations
    unordered_map<string,int> wordCount;
    vector<string> words = {"the","quick","brown","fox","the","quick","the"};
    for (auto& w : words) wordCount[w]++;

    cout << "\nWord counts:\n";
    for (auto& [word, cnt] : wordCount)
        cout << "  " << word << ": " << cnt << "\n";

    // map.lower_bound and upper_bound for range queries
    map<int,int> m = {{1,10},{3,30},{5,50},{7,70},{9,90}};
    int lo = 3, hi = 7;
    cout << "\nKeys in [" << lo << "," << hi << "]:\n";
    for (auto it = m.lower_bound(lo); it != m.upper_bound(hi); ++it)
        cout << "  key=" << it->first << " val=" << it->second << "\n";

    return 0;
}
