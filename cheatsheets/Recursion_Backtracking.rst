.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> Backtracking = choose, explore, unchoose. Always undo what you did. </span>
      <span style="color:#0f766e;">Prune: skip invalid choices early to avoid exploring dead branches.</span>
   </div>

===================================
🔁 Recursion & Backtracking Cheatsheet
===================================

----

🧠 Recursion Mental Model
==========================

.. code-block:: text

    1. Base case: smallest valid input → return directly
    2. Recursive case: reduce to smaller subproblem
    3. Combine: use subproblem result to build answer

    Always ask:
    - What does the function return?
    - What is the base case?
    - How does this call reduce to a smaller problem?

----

🎯 Backtracking Template
=========================

.. code-block:: cpp

    void backtrack(state, choices, result) {
        if (isComplete(state)) {
            result.push_back(state);
            return;
        }
        for (choice : choices) {
            if (!isValid(choice, state)) continue;  // prune
            applyChoice(choice, state);
            backtrack(state, remaining_choices, result);
            undoChoice(choice, state);              // backtrack
        }
    }

----

📦 Generate All Subsets (Power Set)
=====================================

.. code-block:: cpp

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int)> bt = [&](int start) {
            res.push_back(cur);
            for (int i = start; i < (int)nums.size(); i++) {
                cur.push_back(nums[i]);
                bt(i + 1);
                cur.pop_back();
            }
        };
        bt(0);
        return res;
    }

    // Bitmask approach (iterative)
    vector<vector<int>> subsetsBitmask(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> sub;
            for (int i = 0; i < n; i++)
                if (mask & (1 << i)) sub.push_back(nums[i]);
            res.push_back(sub);
        }
        return res;
    }

----

🔀 Generate Permutations
=========================

.. code-block:: cpp

    vector<vector<int>> permutations(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return res;
    }

    // Backtracking approach (swap-based)
    void permBT(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == (int)nums.size()) { res.push_back(nums); return; }
        for (int i = start; i < (int)nums.size(); i++) {
            swap(nums[start], nums[i]);
            permBT(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }

----

🎯 Combination Sum
==================

.. code-block:: cpp

    // Elements can be reused; find all combos summing to target
    vector<vector<int>> combinationSum(vector<int>& cands, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(cands.begin(), cands.end());
        function<void(int, int)> bt = [&](int start, int rem) {
            if (rem == 0) { res.push_back(cur); return; }
            for (int i = start; i < (int)cands.size(); i++) {
                if (cands[i] > rem) break;       // pruning
                cur.push_back(cands[i]);
                bt(i, rem - cands[i]);           // i (not i+1): allow reuse
                cur.pop_back();
            }
        };
        bt(0, target);
        return res;
    }

----

♛ N-Queens
===========

.. code-block:: cpp

    int totalNQueens(int n) {
        int count = 0;
        vector<bool> col(n,false), diag1(2*n,false), diag2(2*n,false);
        function<void(int)> bt = [&](int row) {
            if (row == n) { count++; return; }
            for (int c = 0; c < n; c++) {
                if (col[c] || diag1[row+c] || diag2[row-c+n]) continue;
                col[c] = diag1[row+c] = diag2[row-c+n] = true;
                bt(row + 1);
                col[c] = diag1[row+c] = diag2[row-c+n] = false;
            }
        };
        bt(0);
        return count;
    }

----

🧩 Sudoku Solver
=================

.. code-block:: cpp

    bool solveSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') continue;
                for (char ch = '1'; ch <= '9'; ch++) {
                    if (isValid(board, r, c, ch)) {
                        board[r][c] = ch;
                        if (solveSudoku(board)) return true;
                        board[r][c] = '.';        // backtrack
                    }
                }
                return false;  // no valid digit found
            }
        }
        return true;  // all cells filled
    }

----

🔤 Word Search
===============

.. code-block:: cpp

    bool wordSearch(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        function<bool(int,int,int)> dfs = [&](int r, int c, int idx) -> bool {
            if (idx == (int)word.size()) return true;
            if (r < 0 || r >= n || c < 0 || c >= m) return false;
            if (board[r][c] != word[idx]) return false;
            char tmp = board[r][c];
            board[r][c] = '#';  // mark visited
            bool found = dfs(r+1,c,idx+1) || dfs(r-1,c,idx+1) ||
                         dfs(r,c+1,idx+1) || dfs(r,c-1,idx+1);
            board[r][c] = tmp;  // restore
            return found;
        };
        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++)
                if (dfs(r, c, 0)) return true;
        return false;
    }
