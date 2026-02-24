Day 02 — Mastering Arrays in C++
=================================

Data Structures & Algorithms Mastery — *30 Days to DSA*

Arrays are the foundation of almost every major data structure. Mastering them means
understanding memory layout, indexing, iteration patterns, pointer relationships, and
performance implications. Today's goal is to build an intuitive and technical
understanding of arrays so strong that every future DSA topic feels easier.

1. What You Will Learn Today
-----------------------------

- How arrays are stored in contiguous memory
- Indexing, iteration, and boundary rules
- Static vs dynamic arrays
- Common array operations and their time complexities
- How arrays relate to pointers
- How to avoid common pitfalls (overflow, uninitialized memory, dangling pointers)

2. Why Arrays Matter
---------------------

Arrays are the backbone of:

- Strings
- Hash tables
- Heaps
- Graph adjacency lists
- Dynamic arrays (vector)
- Matrix operations
- Sorting algorithms

If you understand arrays deeply, you understand memory deeply — and that's the real power.

3. Memory Layout of Arrays
---------------------------

An array is a **contiguous block of memory**.

Example::

    int arr[5] = {10, 20, 30, 40, 50};

Memory representation:

=====  =====  ==================
Index  Value  Address (example)
=====  =====  ==================
0      10     0x1000
1      20     0x1004
2      30     0x1008
3      40     0x100C
4      50     0x1010
=====  =====  ==================

Each ``int`` takes 4 bytes → addresses increase by 4.

4. Time Complexity of Array Operations
---------------------------------------

====================  ================  ==============================================
Operation             Complexity        Notes
====================  ================  ==============================================
Access by index       O(1)              Direct address computation
Update                O(1)              Same as access
Insert at end         O(1) amortized    For static arrays: O(1) if space exists
Insert at beginning   O(n)              Shift all elements
Delete at end         O(1)              Just reduce size
Delete at index       O(n)              Shift elements
====================  ================  ==============================================

5. Example Programs
--------------------

Example 1 — Basic Array Input & Output
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: cpp

    #include <iostream>
    using namespace std;

    int main() {
        int arr[5];

        cout << "Enter 5 numbers: ";
        for (int i = 0; i < 5; i++)
            cin >> arr[i];

        cout << "You entered: ";
        for (int i = 0; i < 5; i++)
            cout << arr[i] << " ";

        return 0;
    }

Example 2 — Find Maximum Element
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: cpp

    #include <iostream>
    using namespace std;

    int main() {
        int arr[7] = {12, 45, 2, 67, 33, 90, 10};
        int maxVal = arr[0];

        for (int i = 1; i < 7; i++)
            if (arr[i] > maxVal)
                maxVal = arr[i];

        cout << "Maximum: " << maxVal;
    }

Example 3 — Reverse an Array
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: cpp

    #include <iostream>
    using namespace std;

    int main() {
        int arr[6] = {1, 2, 3, 4, 5, 6};
        int start = 0, end = 5;

        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }

        for (int i = 0; i < 6; i++)
            cout << arr[i] << " ";
    }

Example 4 — Linear Search
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: cpp

    using namespace std;

    int main() {
        int arr[8] = {5, 9, 3, 7, 2, 8, 1, 4};
        int key = 7;

        for (int i = 0; i < 8; i++) {
            if (arr[i] == key) {
                cout << "Found at index " << i;
                return 0;
            }
        }

        cout << "Not found";
    }

6. Pointer Relationship with Arrays
-------------------------------------

Arrays and pointers are deeply connected.

::

    int arr[5];
    arr == &arr[0]

``arr + 1`` moves to the next element.

Example:

.. code-block:: cpp

    cout << *(arr + 2);   // same as arr[2]

7. Common Mistakes to Avoid
-----------------------------

- Accessing out-of-bounds indices
- Using uninitialized arrays
- Forgetting array size
- Confusing array name with pointer variable
- Passing arrays incorrectly to functions

8. Exercises (With Solutions Below)
-------------------------------------

Exercise 1
~~~~~~~~~~

Write a program to count how many numbers in an array are even.

Exercise 2
~~~~~~~~~~

Find the second largest element in an array.

Exercise 3
~~~~~~~~~~

Rotate an array to the right by 1 position.

Exercise 4
~~~~~~~~~~

Check if an array is sorted in non-decreasing order.

9. Solutions
-------------

Solution 1 — Count Even Numbers
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: cpp

    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 == 0)
            count++;

Solution 2 — Second Largest
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: cpp

    int largest = -1e9, second = -1e9;

    for (int x : arr) {
        if (x > largest) {
            second = largest;
            largest = x;
        } else if (x > second && x != largest) {
            second = x;
        }
    }

Solution 3 — Rotate Right by 1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: cpp

    int last = arr[n-1];
    for (int i = n-1; i > 0; i--)
        arr[i] = arr[i-1];
    arr[0] = last;

Solution 4 — Check Sorted
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: cpp

    bool sorted = true;
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[i-1])
            sorted = false;

10. Summary
------------

Today you learned:

- How arrays work internally
- How to manipulate them efficiently
- How to avoid common pitfalls
- How arrays connect to pointers
- How to implement essential array algorithms

This foundation will make future topics like strings, linked lists, stacks, queues, and dynamic arrays much easier.


.. quality-upgrade-2026-02-20

Quality Upgrade: Active Recall + Practice
-----------------------------------------

Quick Revision Checklist
~~~~~~~~~~~~~~~~~~~~~~~~

- Summarize the pattern in one sentence.
- List brute-force vs optimized complexity.
- Note edge cases and failure modes.
- Re-solve one problem without notes.

Common Mistakes to Avoid
~~~~~~~~~~~~~~~~~~~~~~~~

- Jumping to code before constraints analysis.
- Ignoring input bounds when selecting approach.
- Skipping dry run for corner cases.
- Not validating invariant after each loop iteration.

Practice Ladder (Progressive)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Easy: one direct template problem.
- Medium: one variant with constraints twist.
- Hard: one mixed-topic interview-style problem.

