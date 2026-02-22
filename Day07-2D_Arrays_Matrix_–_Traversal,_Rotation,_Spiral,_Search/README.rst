---

## **1. Introduction**

2D arrays (matrices) are everywhere in DSA:

- Image processing  
- Dynamic programming  
- Graphs  
- Grid‑based BFS/DFS  
- Prefix sum matrices  
- Searching and sorting in 2D  
- Simulation problems  
- Matrix rotation and transformation  

Today’s goal is to master:

- Matrix traversal patterns  
- Row‑wise and column‑wise operations  
- Spiral traversal  
- Matrix rotation (90°, 180°, 270°)  
- Searching in sorted matrices  
- Boundary traversal  
- Diagonal traversal  
- Real interview problems  

This is one of the most important days for building intuition for grid‑based problems.

---

## **2. Basic Matrix Traversal**

### **2.1 Row‑wise traversal**

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        cout << mat[i][j] << " ";
```

---

### **2.2 Column‑wise traversal**

```cpp
for (int j = 0; j < m; j++)
    for (int i = 0; i < n; i++)
        cout << mat[i][j] << " ";
```

---

## **3. Boundary Traversal**

```cpp
// top row
for (int j = 0; j < m; j++) cout << mat[0][j] << " ";

// right column
for (int i = 1; i < n; i++) cout << mat[i][m-1] << " ";

// bottom row
if (n > 1)
    for (int j = m-2; j >= 0; j--) cout << mat[n-1][j] << " ";

// left column
if (m > 1)
    for (int i = n-2; i > 0; i--) cout << mat[i][0] << " ";
```

---

## **4. Diagonal Traversal**

### **4.1 Primary diagonal**

```cpp
for (int i = 0; i < n; i++)
    cout << mat[i][i] << " ";
```

---

### **4.2 Secondary diagonal**

```cpp
for (int i = 0; i < n; i++)
    cout << mat[i][n-i-1] << " ";
```

---

## **5. Spiral Traversal (Very Important)**

This is a classic interview problem.

```cpp
int top = 0, bottom = n - 1;
int left = 0, right = m - 1;

while (top <= bottom && left <= right) {

    for (int j = left; j <= right; j++)
        cout << mat[top][j] << " ";
    top++;

    for (int i = top; i <= bottom; i++)
        cout << mat[i][right] << " ";
    right--;

    if (top <= bottom) {
        for (int j = right; j >= left; j--)
            cout << mat[bottom][j] << " ";
        bottom--;
    }

    if (left <= right) {
        for (int i = bottom; i >= top; i--)
            cout << mat[i][left] << " ";
        left++;
    }
}
```

---

## **6. Rotate Matrix by 90° Clockwise**

### **Step 1: Transpose**

```cpp
for (int i = 0; i < n; i++)
    for (int j = i; j < m; j++)
        swap(mat[i][j], mat[j][i]);
```

### **Step 2: Reverse each row**

```cpp
for (int i = 0; i < n; i++)
    reverse(mat[i].begin(), mat[i].end());
```

---

## **7. Rotate Matrix by 90° Anti‑Clockwise**

### **Step 1: Transpose**

### **Step 2: Reverse each column**

```cpp
for (int j = 0; j < m; j++) {
    int top = 0, bottom = n - 1;
    while (top < bottom)
        swap(mat[top++][j], mat[bottom--][j]);
}
```

---

## **8. Searching in a Sorted Matrix**

---

### **8.1 Row‑wise and column‑wise sorted matrix (Staircase Search)**

Matrix property:

- Rows sorted left → right  
- Columns sorted top → bottom  

Start at top‑right:

```cpp
int i = 0, j = m - 1;

while (i < n && j >= 0) {
    if (mat[i][j] == target) return true;
    else if (mat[i][j] > target) j--;
    else i++;
}
```

Time: O(n + m)

---

### **8.2 Fully sorted matrix (Binary Search)**

Matrix is sorted row‑wise and each row starts with a value greater than previous row.

Treat matrix as 1D array:

```cpp
int l = 0, r = n*m - 1;

while (l <= r) {
    int mid = (l + r) / 2;
    int val = mat[mid / m][mid % m];

    if (val == target) return true;
    else if (val < target) l = mid + 1;
    else r = mid - 1;
}
```

Time: O(log(n*m))

---

## **9. Real‑World Examples**

---

### **Example 1 — Print matrix in wave form**

```cpp
for (int j = 0; j < m; j++) {
    if (j % 2 == 0)
        for (int i = 0; i < n; i++) cout << mat[i][j] << " ";
    else
        for (int i = n-1; i >= 0; i--) cout << mat[i][j] << " ";
}
```

---

### **Example 2 — Transpose matrix**

```cpp
for (int i = 0; i < n; i++)
    for (int j = i; j < m; j++)
        swap(mat[i][j], mat[j][i]);
```

---

### **Example 3 — Count number of 1s in each row**

```cpp
for (int i = 0; i < n; i++) {
    int cnt = count(mat[i].begin(), mat[i].end(), 1);
}
```

---

### **Example 4 — Maximum element in matrix**

```cpp
int mx = INT_MIN;
for (auto &row : mat)
    for (int x : row)
        mx = max(mx, x);
```

---

## **10. Interview‑Level Problems**

---

### **Problem 1 — Spiral traversal**  
Classic.

---

### **Problem 2 — Rotate matrix by 90°**  
Transpose + reverse.

---

### **Problem 3 — Search in sorted matrix**  
Staircase search.

---

### **Problem 4 — Set matrix zeroes**  
Use row/column markers.

---

### **Problem 5 — Print matrix diagonally**  
Use i+j constant diagonals.

---

## **11. Exercises (Try First)**

---

### **Exercise 1**  
Print matrix in spiral order.

---

### **Exercise 2**  
Rotate matrix by 90° clockwise.

---

### **Exercise 3**  
Search for a target in a row‑wise and column‑wise sorted matrix.

---

### **Exercise 4**  
Print matrix in wave form.

---

### **Exercise 5**  
Given a matrix, set entire row and column to zero if an element is zero.

---

## **12. Solutions**

---

### **Solution 1 — Spiral order**

Use the spiral template from section 5.

---

### **Solution 2 — Rotate 90°**

Transpose + reverse rows.

---

### **Solution 3 — Search in sorted matrix**

Use staircase search.

---

### **Solution 4 — Wave form**

Use alternating up/down traversal.

---

### **Solution 5 — Set matrix zeroes**

```cpp
vector<int> row(n, 0), col(m, 0);

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (mat[i][j] == 0)
            row[i] = col[j] = 1;

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (row[i] || col[j])
            mat[i][j] = 0;
```

---

## **13. Summary**

Today you mastered:

- Matrix traversal patterns  
- Boundary and diagonal traversal  
- Spiral traversal  
- Matrix rotation (90°, 180°, 270°)  
- Searching in sorted matrices  
- Wave traversal  
- Real interview problems  

Matrix problems appear everywhere — DP, graphs, BFS/DFS, simulations, and more.  
This day builds the foundation for many advanced topics.

---

.. quality-upgrade-2026-02-20

Quality Upgrade: Active Recall + Practice
-----------------------------------------

Quick Revision Checklist
~~~~~~~~~~~~~~~~~~~~~~~~

- Differentiate when to use two pointers vs sliding window.
- Re-derive prefix sum query formula in O(1).
- Explain difference array update and final reconstruction.
- List edge cases: empty input, single element, all duplicates.

Common Mistakes to Avoid
~~~~~~~~~~~~~~~~~~~~~~~~

- Off-by-one in subarray boundaries.
- Mutating array while iterating without index discipline.
- Using O(n^2) when prefix/hash can reduce to O(n).
- Ignoring overflow when summing large ranges.

Practice Ladder (Progressive)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Easy: move zeroes, remove duplicates.
- Medium: longest subarray with given sum/k constraints.
- Hard: 2D prefix sum + range update mix.

