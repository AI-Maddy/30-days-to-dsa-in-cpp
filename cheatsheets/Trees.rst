.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> Inorder of BST = sorted array. LCA: if both nodes on same side, go that way; else current = LCA. </span>
      <span style="color:#0f766e;">Height = max(leftHeight, rightHeight) + 1. Diameter = max over all nodes of (leftH + rightH).</span>
   </div>

=====================
🌳 Trees Cheatsheet
=====================

----

🏗️ Node Definition
====================

.. code-block:: cpp

    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

----

🔄 DFS Traversals
==================

.. code-block:: cpp

    // Recursive inorder (left, root, right)
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    // Iterative inorder using stack
    vector<int> inorderIter(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr || !st.empty()) {
            while (curr) { st.push(curr); curr = curr->left; }
            curr = st.top(); st.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }

    // Morris Inorder — O(n) time, O(1) space
    vector<int> morrisInorder(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) { res.push_back(curr->val); curr = curr->right; }
            else {
                TreeNode* pre = curr->left;
                while (pre->right && pre->right != curr) pre = pre->right;
                if (!pre->right) { pre->right = curr; curr = curr->left; }
                else { pre->right = nullptr; res.push_back(curr->val); curr = curr->right; }
            }
        }
        return res;
    }

    // Preorder iterative
    vector<int> preorderIter(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top(); st.pop();
            res.push_back(node->val);
            if (node->right) st.push(node->right);
            if (node->left)  st.push(node->left);
        }
        return res;
    }

----

🔍 BFS Level Order
===================

.. code-block:: cpp

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;
            for (int i = 0; i < sz; i++) {
                auto node = q.front(); q.pop();
                level.push_back(node->val);
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(level);
        }
        return res;
    }

----

📏 Height & Diameter
=====================

.. code-block:: cpp

    int height(TreeNode* root) {
        if (!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }

    int diameter(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node) return 0;
            int l = dfs(node->left), r = dfs(node->right);
            ans = max(ans, l + r);
            return max(l, r) + 1;
        };
        dfs(root);
        return ans;
    }

----

🤝 Lowest Common Ancestor (LCA)
================================

.. code-block:: cpp

    // Binary Tree LCA
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        auto left  = lca(root->left,  p, q);
        auto right = lca(root->right, p, q);
        if (left && right) return root;   // p and q on different sides
        return left ? left : right;
    }

    // BST LCA — O(h)
    TreeNode* lcaBST(TreeNode* root, int p, int q) {
        while (root) {
            if (p < root->val && q < root->val) root = root->left;
            else if (p > root->val && q > root->val) root = root->right;
            else return root;
        }
        return nullptr;
    }

----

🔍 BST Operations
==================

.. code-block:: cpp

    // Insert
    TreeNode* insert(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val) root->left  = insert(root->left,  val);
        else                 root->right = insert(root->right, val);
        return root;
    }

    // Validate BST
    bool isValidBST(TreeNode* root, long lo = LONG_MIN, long hi = LONG_MAX) {
        if (!root) return true;
        if (root->val <= lo || root->val >= hi) return false;
        return isValidBST(root->left, lo, root->val) &&
               isValidBST(root->right, root->val, hi);
    }

    // Kth smallest (inorder)
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr || !st.empty()) {
            while (curr) { st.push(curr); curr = curr->left; }
            curr = st.top(); st.pop();
            if (--k == 0) return curr->val;
            curr = curr->right;
        }
        return -1;
    }

    // Floor in BST (largest value <= key)
    int floor(TreeNode* root, int key) {
        int res = -1;
        while (root) {
            if (root->val == key) return key;
            if (root->val < key) { res = root->val; root = root->right; }
            else root = root->left;
        }
        return res;
    }
