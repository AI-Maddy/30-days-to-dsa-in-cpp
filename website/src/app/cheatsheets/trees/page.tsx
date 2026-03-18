import React from "react";
import { FaTree } from "react-icons/fa";

export default function TreesCheatsheet() {
  return (
    <div className="prose max-w-2xl mx-auto p-6 bg-white/90 rounded-xl shadow-lg mt-8">
      <h1 className="flex items-center gap-2 text-green-700"><FaTree /> Trees Cheatsheet</h1>
      <div className="bg-indigo-100 border-l-4 border-indigo-500 text-indigo-900 p-4 mb-4 rounded">
        <strong>🧠 Memory Aid:</strong> Inorder of BST = sorted array. LCA: if both nodes on same side, go that way; else current = LCA. <span className="text-emerald-700">Height = max(leftHeight, rightHeight) + 1. Diameter = max over all nodes of (leftH + rightH).</span>
      </div>
      <h2>🏕️ Node Definition</h2>
      <pre className="bg-zinc-100 p-2 rounded text-xs overflow-x-auto"><code>{`struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};`}</code></pre>
      {/* ...more content can be added here... */}
    </div>
  );
}
