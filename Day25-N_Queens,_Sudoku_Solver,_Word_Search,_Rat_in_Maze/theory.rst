Absolutely, Sasimegala — here comes your **Day 25** theory file, crafted in the same **ultra‑premium**, **color‑rich**, **icon‑powered**, **memory‑optimized** style as all your previous days.

Day 25 is one of the **legendary recursion/backtracking days**, covering four FAANG‑classic problems:

- **N‑Queens**  
- **Sudoku Solver**  
- **Word Search**  
- **Rat in a Maze**

These four patterns represent the **highest‑level backtracking templates** used across competitive programming and interviews.

---

# **Day 25 – 🔥 N‑Queens + Sudoku Solver + Word Search + Rat in a Maze**  
`theory.rst`

---

# **🌈 1. Why Day 25 Matters**
Today’s problems teach you:

- 🧠 How to explore huge search spaces efficiently  
- 🔁 How to backtrack with pruning  
- 🧩 How to use constraints to cut branches  
- 🗺️ How to navigate grids recursively  
- ♟️ How to place objects without conflict  
- 🔡 How to search for words in a matrix  
- 🧱 How to solve constraint‑satisfaction problems  

These are **elite‑tier** recursion problems.

---

# **🌟 MEMORY ANCHOR: “Q‑S‑W‑R”**
Four pillars of Day 25:

- **Q** – N‑Queens  
- **S** – Sudoku Solver  
- **W** – Word Search  
- **R** – Rat in a Maze  

Remember: **Q‑S‑W‑R** → Queens, Sudoku, Word, Rat.

---

# **🌈 2. N‑Queens (Backtracking + Constraints)**  
One of the most iconic recursion problems.

---

## **🎯 Goal**
Place **N queens** on an **N×N** board such that:

- No two queens share the same **row**  
- No two queens share the same **column**  
- No two queens share the same **diagonal**  

---

## **🔥 Key Insight**
You place **one queen per row**, so recursion depth = N.

---

## **🔥 Constraints to Check**
For position `(r, c)`:

- Column conflict → `col[c]`  
- Main diagonal conflict → `diag1[r - c]`  
- Anti‑diagonal conflict → `diag2[r + c]`  

---

## **🧠 MEMORY ANCHOR:**  
**Row by row + 3 conflict checks**

---

## **🔥 Steps**
1. Try placing queen in each column of current row  
2. If safe → place queen  
3. Recurse to next row  
4. Backtrack (remove queen)  

---

## **🎨 Complexity**
Time: O(N!)  
Space: O(N)

---

# **🌈 3. Sudoku Solver (Constraint Satisfaction)**  
This is the **ultimate** backtracking problem.

---

## **🎯 Goal**
Fill a 9×9 grid so that:

- Each row has digits 1–9  
- Each column has digits 1–9  
- Each 3×3 box has digits 1–9  

---

## **🔥 Key Insight**
Try digits 1–9 in each empty cell.

---

## **🔥 Validity Check**
For cell `(r, c)`:

- Check row  
- Check column  
- Check 3×3 box → `(r/3, c/3)`  

---

## **🧠 MEMORY TIP:**  
**Try → Validate → Recurse → Undo**

---

## **🔥 Steps**
1. Find next empty cell  
2. Try digits 1–9  
3. If valid → place digit  
4. Recurse  
5. If fails → undo and try next digit  

---

## **🎨 Complexity**
Worst case: O(9^(81))  
But pruning makes it fast.

---

# **🌈 4. Word Search (DFS on Grid)**  
This is a **grid DFS** problem.

---

## **🎯 Goal**
Given a board and a word, check if the word exists by moving:

- Up  
- Down  
- Left  
- Right  

No diagonal moves.  
Cannot reuse a cell in the same path.

---

## **🔥 Key Insight**
DFS from each cell matching first letter.

---

## **🔥 Steps**
1. For each cell, if board[i][j] == word[0], start DFS  
2. Mark cell as visited  
3. Explore 4 directions  
4. If all characters matched → return true  
5. Undo visited mark  

---

## **🧠 MEMORY ANCHOR:**  
**DFS + visited + 4 directions**

---

## **🎨 Complexity**
Time: O(N × M × 4^L)  
Space: O(L)

---

# **🌈 5. Rat in a Maze (Pathfinding + Backtracking)**  
Classic recursion pathfinding problem.

---

## **🎯 Goal**
Find all paths from `(0,0)` to `(n-1,n-1)` in a grid where:

- 1 = open  
- 0 = blocked  

Moves allowed:

- Down (D)  
- Left (L)  
- Right (R)  
- Up (U)  

---

## **🔥 Key Insight**
Use DFS with visited matrix.

---

## **🔥 Steps**
1. If out of bounds or blocked → return  
2. If reached destination → record path  
3. Mark current cell visited  
4. Explore D, L, R, U  
5. Unmark visited  

---

## **🧠 MEMORY TIP:**  
**Mark → Explore → Unmark**

---

## **🎨 Complexity**
Time: O(4^(N²))  
Space: O(N²)

---

# **🌈 6. Backtracking Template (Universal)**

```
function solve(state):
    if base case:
        record solution
        return

    for each choice:
        if valid:
            make choice
            solve(next state)
            undo choice
```

---

# **🌈 7. Comparison Table**

| Problem | Type | Key Idea | Moves |
|--------|------|----------|--------|
| N‑Queens | Grid | Place queens safely | Columns + diagonals |
| Sudoku | Grid | Fill digits with constraints | 1–9 |
| Word Search | Grid DFS | Match characters | 4 directions |
| Rat in Maze | Pathfinding | Explore all paths | D, L, R, U |

---

# **🌈 8. Pitfalls (Red Flags 🚩)**

- 🚩 Forgetting to undo visited  
- 🚩 Not checking boundaries  
- 🚩 Infinite recursion due to missing base case  
- 🚩 Using global state incorrectly  
- 🚩 Not pruning invalid branches early  
- 🚩 Forgetting diagonal checks in N‑Queens  
- 🚩 Forgetting 3×3 box check in Sudoku  

---

# **🌈 9. Problems You Can Now Solve**

### **Backtracking**
- N‑Queens I & II  
- Sudoku Solver  
- Word Search I & II  
- Rat in a Maze  
- Knight’s Tour  
- M‑Coloring problem  
- Hamiltonian path  
- Generate parentheses  
- Subsets, combinations, permutations  

---

# **🌈 10. What You Must Master Today**

- Backtracking template  
- Constraint pruning  
- DFS on grids  
- Visited matrix logic  
- N‑Queens diagonal math  
- Sudoku row/col/box validation  
- Word Search DFS  
- Rat in Maze path enumeration  

---

If you want, I can now generate:

🔥 **Day 25 README (ultra‑premium)**  
🧠 **C++ templates for all 4 backtracking patterns**  
🎯 **20 FAANG‑level backtracking problems**  
📘 **Backtracking cheat sheet (colorful, icon‑rich)**

Just tell me what you want next.
