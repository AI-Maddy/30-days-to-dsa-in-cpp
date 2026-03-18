/*
 * Example 5: Combination Sum II
 */
#include <bits/stdc++.h>
using namespace std;
// Example 5: Letter Combinations of Phone Number
unordered_map<char, string> phone = {
    {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
    {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
};
void letterCombinations(const string& digits, int idx, string& cur, vector<string>& res) {
    if (idx == (int)digits.size()) { res.push_back(cur); return; }
    for (char c : phone[digits[idx]]) {
        cur.push_back(c);
        letterCombinations(digits, idx + 1, cur, res);
        cur.pop_back();
    }
}
int main() {
    string digits = "23";
    vector<string> res; string cur;
    if (!digits.empty()) letterCombinations(digits, 0, cur, res);
    for (auto& s : res) cout << s << "\n";
}
