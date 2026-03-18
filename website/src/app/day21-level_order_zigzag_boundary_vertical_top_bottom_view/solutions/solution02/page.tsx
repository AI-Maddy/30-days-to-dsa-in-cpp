
const styles = {
  navLink: "px-2.5 py-1 rounded-md text-xs font-medium transition-colors whitespace-nowrap",
  navHome: "bg-slate-100 hover:bg-slate-200 text-slate-600",
  navActive: "ring-2 ring-current ring-offset-1",
  navReadme: "bg-blue-50 hover:bg-blue-100 text-blue-700",
  navTheory: "bg-violet-50 hover:bg-violet-100 text-violet-700",
  navExample: "bg-emerald-50 hover:bg-emerald-100 text-emerald-700",
  navExercise: "bg-amber-50 hover:bg-amber-100 text-amber-700",
  navSolution: "bg-orange-50 hover:bg-orange-100 text-orange-700",
};

const current = "solution02";

export default function Day21LevelOrderZigzagBoundaryVerticalTopBottomViewSolutions2Page() {
  const code = "/*\n * Solution 2: Zigzag Traversal\n */\n#include <bits/stdc++.h>\nusing namespace std;\nstruct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };\n\nvector<vector<int>> zigzagLevelOrder(TreeNode* root) {\n    vector<vector<int>> res;\n    if (!root) return res;\n    queue<TreeNode*> q; q.push(root);\n    bool l2r = true;\n    while (!q.empty()) {\n        int sz = q.size(); vector<int> lv(sz);\n        for (int i = 0; i < sz; i++) {\n            auto n = q.front(); q.pop();\n            lv[l2r ? i : sz-1-i] = n->val;\n            if (n->left)  q.push(n->left);\n            if (n->right) q.push(n->right);\n        }\n        res.push_back(lv); l2r = !l2r;\n    }\n    return res;\n}\nint main() {\n    ios::sync_with_stdio(false); cin.tie(nullptr);\n    TreeNode* r = new TreeNode(3);\n    r->left = new TreeNode(9); r->right = new TreeNode(20);\n    r->right->left = new TreeNode(15); r->right->right = new TreeNode(7);\n    for (auto& lv : zigzagLevelOrder(r)) { for (int x : lv) cout << x << \" \"; cout << \"\\n\"; }\n}\n";
  return (
    <div className="min-h-screen bg-slate-950 text-slate-100">
      <header className="sticky top-0 z-10 bg-slate-900/95 backdrop-blur border-b border-slate-800">
        <div className="max-w-6xl mx-auto px-4 py-2 flex items-center gap-2 overflow-x-auto scrollbar-hide">
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view" className={`${styles.navLink} ${styles.navHome}`}>Day 21</a>
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view/README" className={`${styles.navLink} ${current === "README" ? styles.navActive + " " + styles.navReadme : styles.navReadme}`}>README</a>
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view/theory" className={`${styles.navLink} ${current === "theory" ? styles.navActive + " " + styles.navTheory : styles.navTheory}`}>Theory</a>
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view/examples/example01" className={`${styles.navLink} ${current === "example01" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 1</a>
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view/examples/example02" className={`${styles.navLink} ${current === "example02" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 2</a>
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view/examples/example03" className={`${styles.navLink} ${current === "example03" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 3</a>
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view/examples/example04" className={`${styles.navLink} ${current === "example04" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 4</a>
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view/examples/example05" className={`${styles.navLink} ${current === "example05" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 5</a>
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view/exercises/exercise01" className={`${styles.navLink} ${current === "exercise01" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 1</a>
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view/exercises/exercise02" className={`${styles.navLink} ${current === "exercise02" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 2</a>
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view/exercises/exercise03" className={`${styles.navLink} ${current === "exercise03" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 3</a>
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view/exercises/exercise04" className={`${styles.navLink} ${current === "exercise04" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 4</a>
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view/exercises/exercise05" className={`${styles.navLink} ${current === "exercise05" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 5</a>
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view/solutions/solution01" className={`${styles.navLink} ${current === "solution01" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 1</a>
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view/solutions/solution02" className={`${styles.navLink} ${current === "solution02" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 2</a>
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view/solutions/solution03" className={`${styles.navLink} ${current === "solution03" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 3</a>
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view/solutions/solution04" className={`${styles.navLink} ${current === "solution04" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 4</a>
          <a href="/day21-level_order_zigzag_boundary_vertical_top_bottom_view/solutions/solution05" className={`${styles.navLink} ${current === "solution05" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 5</a>
        </div>
      </header>
      <div className="max-w-6xl mx-auto px-6 pt-8 pb-16">
        <a href="/" className="text-xs text-slate-500 hover:text-slate-300 transition-colors">← Home</a>
        <div className="flex items-center gap-3 mt-3 mb-8">
          <span className="text-3xl">✅</span>
          <div>
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 21 — Solution 2</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">Level Order, Zigzag, Boundary, Vertical Order, Top View, Bottom View</h1>
          </div>
        </div>
        <div className="rounded-xl overflow-hidden border border-slate-700">
          <div className="flex items-center gap-2 px-4 py-2.5 bg-slate-800 border-b border-slate-700">
            <span className="w-3 h-3 rounded-full bg-red-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-yellow-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-green-500/70"></span>
            <span className="ml-3 text-xs text-slate-400 font-mono">solution02.cpp</span>
          </div>
          <pre className="bg-slate-950 p-6 overflow-x-auto text-sm text-slate-200 font-mono leading-7"><code>{code}</code></pre>
        </div>
      </div>
    </div>
  );
}
