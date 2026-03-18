import React from "react";
import { FaLink } from "react-icons/fa";

export default function LinkedListsCheatsheet() {
  return (
    <div className="prose max-w-2xl mx-auto p-6 bg-white/90 rounded-xl shadow-lg mt-8">
      <h1 className="flex items-center gap-2 text-green-600"><FaLink /> Linked Lists Cheatsheet</h1>
      <div className="bg-indigo-100 border-l-4 border-indigo-500 text-indigo-900 p-4 mb-4 rounded">
        <strong>🧠 Memory Aid:</strong> Use dummy head to simplify edge cases. Fast/slow pointers for middle and cycle detection. <span className="text-emerald-700">Reverse: prev=null, curr=head, save next, rewire, advance.</span>
      </div>
      <h2>🏕️ Node Definition</h2>
      <pre className="bg-zinc-100 p-2 rounded text-xs overflow-x-auto"><code>{`struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Doubly linked list
struct DNode {
    int val;
    DNode* prev;
    DNode* next;
    DNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

// Helper: build list from vector
ListNode* build(vector<int> v) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int x : v) { cur->next = new ListNode(x); cur = cur->next; }`}</code></pre>
      {/* ...more content can be added here... */}
    </div>
  );
}
