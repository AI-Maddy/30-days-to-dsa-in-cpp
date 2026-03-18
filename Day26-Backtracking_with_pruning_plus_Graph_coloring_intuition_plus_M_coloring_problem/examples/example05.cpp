/*
 * Example 5: Restore IP Addresses
 */
#include <bits/stdc++.h>
using namespace std;
// Example 5: Expression Add Operators (add +,-,* between digits to reach target)
void addOperators(const string& num, int pos, long long eval, long long mult,
                  string cur, int target, vector<string>& res) {
    if (pos == (int)num.size()) {
        if (eval == target) res.push_back(cur);
        return;
    }
    for (int len = 1; pos + len <= (int)num.size(); len++) {
        string part = num.substr(pos, len);
        if (part.size() > 1 && part[0] == '0') break; // no leading zeros
        long long val = stoll(part);
        if (pos == 0) {
            addOperators(num, len, val, val, part, target, res);
        } else {
            addOperators(num, pos+len, eval+val,    val,    cur+"+"+part, target, res);
            addOperators(num, pos+len, eval-val,   -val,    cur+"-"+part, target, res);
            addOperators(num, pos+len, eval-mult+mult*val, mult*val, cur+"*"+part, target, res);
        }
    }
}
int main() {
    string num = "123"; int target = 6;
    vector<string> res;
    addOperators(num, 0, 0, 0, "", target, res);
    for (auto& s : res) cout << s << "\n";
}
