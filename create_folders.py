import os

# Define the base directory for the repo
BASE_DIR = '.'  # Current directory or specify path

# Define day-wise folder names and topics
day_topics = [
    "C++ STL Mastery", "Time & Space Complexity + STL Algorithms", "Bit Manipulation in C++",
    "1D Arrays – Two Pointers & Sliding Window basics", "Prefix Sum + Difference Array + Range queries patterns",
    "Hashing & HashMap problems", "2D Arrays/Matrix – Traversal, Rotation, Spiral, Search",
    "Binary Search on 1D & 2D + Binary Search on Answer pattern", "Aggressive Cows, Book Allocation, Painters Partition, Median of 2 sorted arrays",
    "Sorting revision + Custom comparators + Counting Sort / Radix Sort intuition", "Binary Search on Sorted Rotated Array + Search in 2D matrix variants",
    "Singly Linked List – Reverse, Middle, Cycle detection, Remove nth node", "Doubly + Circular Linked List + LRU Cache intuition",
    "Fast & Slow pointers deep dive + Palindrome Linked List variants", "Merge k Sorted Lists + Sort Linked List + Flatten multilevel list",
    "Stack – Next Greater Element (NGE), Next Smaller, Stock Span", "Monotonic Stack/Queue patterns + Largest Rectangle in Histogram",
    "Queue + Deque – Sliding Window Maximum, First negative in window", "Parentheses problems + Evaluate Reverse Polish Notation + LFU intuition",
    "Binary Tree Traversals (Recursive + Iterative Morris)", "Level Order, Zigzag, Boundary, Vertical Order, Top View, Bottom View",
    "Binary Search Tree – Validate, Floor/Ceil, Kth smallest, LCA in BST", "Construct Tree from traversals + Serialize/Deserialize + Morris Traversal deep",
    "Recursion basics + Subsets, Combination Sum, Permutations", "N-Queens, Sudoku Solver, Word Search, Rat in Maze",
    "Backtracking with pruning + Graph coloring intuition + M-coloring problem", "Graph Traversals (BFS/DFS) + Flood Fill + Rotten Oranges + Number of Islands",
    "Shortest Path (Dijkstra intro) + Topological Sort + Course Schedule", "Greedy revision + Activity Selection + Fractional Knapsack + Jump Game variants",
    "1D DP patterns + Mini revision + Solve mixed medium-hard problems"
]

# Cheatsheets to create
cheatsheets = [
    "C++_STL.rst", "Complexity_Analysis.rst", "Bit_Manipulation.rst", "Arrays.rst", "Hashing.rst",
    "Binary_Search.rst", "Sorting.rst", "Linked_Lists.rst", "Stacks_Queues.rst", "Trees.rst",
    "Recursion_Backtracking.rst", "Graphs.rst", "Dynamic_Programming.rst"
]

# Scripts to create
scripts = ["setup.py", "run_tests.py", "generate_readme.py"]

# Helper function to create files

def touch_file(path):
    with open(path, 'a'):
        os.utime(path, None)

# Create folder structure and files
for i, topic in enumerate(day_topics, start=1):
    # Replace spaces and special characters with underscores for folder name
    safe_topic = topic.replace(' ', '_').replace('/', '_').replace('&', 'and').replace('-', '_').replace('+', 'plus')
    day_folder = os.path.join(BASE_DIR, f"Day{str(i).zfill(2)}-{safe_topic}")
    os.makedirs(day_folder, exist_ok=True)

    # Create README.rst and theory.rst
    readme_path = os.path.join(day_folder, "README.rst")
    theory_path = os.path.join(day_folder, "theory.rst")
    touch_file(readme_path)
    touch_file(theory_path)

    # Create subfolders
    for subfolder in ["examples", "exercises", "solutions"]:
        subfolder_path = os.path.join(day_folder, subfolder)
        os.makedirs(subfolder_path, exist_ok=True)

        # Create 5 numbered .cpp files
        for j in range(1, 6):
            file_name = f"{subfolder[:-1]}{str(j).zfill(2)}.cpp"  # example01.cpp, exercise01.cpp, solution01.cpp
            file_path = os.path.join(subfolder_path, file_name)
            touch_file(file_path)

# Create cheatsheets folder and files
cheatsheets_folder = os.path.join(BASE_DIR, "cheatsheets")
os.makedirs(cheatsheets_folder, exist_ok=True)
for cheat in cheatsheets:
    cheat_path = os.path.join(cheatsheets_folder, cheat)
    touch_file(cheat_path)

# Create scripts folder and files
scripts_folder = os.path.join(BASE_DIR, "scripts")
os.makedirs(scripts_folder, exist_ok=True)
for script in scripts:
    script_path = os.path.join(scripts_folder, script)
    touch_file(script_path)

print("Folder structure and files created successfully.")