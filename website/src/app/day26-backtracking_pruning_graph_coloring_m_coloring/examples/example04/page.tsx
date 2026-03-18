
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

const current = "example04";

export default function Day26BacktrackingPruningGraphColoringMColoringExamples4Page() {
  const code = "/*\n * Example 4: Unique Permutations\n */\n#include <bits/stdc++.h>\nusing namespace std;\n// Example 4: Unique Permutations (with duplicates, backtracking)\nvoid permuteUnique(vector<int>& nums, vector<bool>& used, vector<int>& cur, vector<vector<int>>& res) {\n    if (cur.size() == nums.size()) { res.push_back(cur); return; }\n    for (int i = 0; i < (int)nums.size(); i++) {\n        if (used[i]) continue;\n        // Skip duplicate: same value, previous one not used (would produce duplicate)\n        if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;\n        used[i] = true;\n        cur.push_back(nums[i]);\n        permuteUnique(nums, used, cur, res);\n        cur.pop_back();\n        used[i] = false;\n    }\n}\nint main() {\n    vector<int> nums = {1, 1, 2}; sort(nums.begin(), nums.end());\n    vector<bool> used(nums.size(), false);\n    vector<vector<int>> res; vector<int> cur;\n    permuteUnique(nums, used, cur, res);\n    for (auto& p : res) { for (int x : p) cout << x << \" \"; cout << \"\\n\"; }\n}\n";
  return (
    <div className="min-h-screen bg-slate-950 text-slate-100">
      <header className="sticky top-0 z-10 bg-slate-900/95 backdrop-blur border-b border-slate-800">
        <div className="max-w-6xl mx-auto px-4 py-2 flex items-center gap-2 overflow-x-auto scrollbar-hide">
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring" className={`${styles.navLink} ${styles.navHome}`}>Day 26</a>
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring/README" className={`${styles.navLink} ${current === "README" ? styles.navActive + " " + styles.navReadme : styles.navReadme}`}>README</a>
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring/theory" className={`${styles.navLink} ${current === "theory" ? styles.navActive + " " + styles.navTheory : styles.navTheory}`}>Theory</a>
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring/examples/example01" className={`${styles.navLink} ${current === "example01" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 1</a>
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring/examples/example02" className={`${styles.navLink} ${current === "example02" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 2</a>
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring/examples/example03" className={`${styles.navLink} ${current === "example03" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 3</a>
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring/examples/example04" className={`${styles.navLink} ${current === "example04" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 4</a>
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring/examples/example05" className={`${styles.navLink} ${current === "example05" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 5</a>
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring/exercises/exercise01" className={`${styles.navLink} ${current === "exercise01" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 1</a>
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring/exercises/exercise02" className={`${styles.navLink} ${current === "exercise02" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 2</a>
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring/exercises/exercise03" className={`${styles.navLink} ${current === "exercise03" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 3</a>
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring/exercises/exercise04" className={`${styles.navLink} ${current === "exercise04" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 4</a>
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring/exercises/exercise05" className={`${styles.navLink} ${current === "exercise05" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 5</a>
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring/solutions/solution01" className={`${styles.navLink} ${current === "solution01" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 1</a>
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring/solutions/solution02" className={`${styles.navLink} ${current === "solution02" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 2</a>
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring/solutions/solution03" className={`${styles.navLink} ${current === "solution03" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 3</a>
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring/solutions/solution04" className={`${styles.navLink} ${current === "solution04" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 4</a>
          <a href="/day26-backtracking_pruning_graph_coloring_m_coloring/solutions/solution05" className={`${styles.navLink} ${current === "solution05" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 5</a>
        </div>
      </header>
      <div className="max-w-6xl mx-auto px-6 pt-8 pb-16">
        <a href="/" className="text-xs text-slate-500 hover:text-slate-300 transition-colors">← Home</a>
        <div className="flex items-center gap-3 mt-3 mb-8">
          <span className="text-3xl">💡</span>
          <div>
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 26 — Example 4</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">Backtracking with pruning plus Graph coloring intuition plus M coloring problem</h1>
          </div>
        </div>
        <div className="rounded-xl overflow-hidden border border-slate-700">
          <div className="flex items-center gap-2 px-4 py-2.5 bg-slate-800 border-b border-slate-700">
            <span className="w-3 h-3 rounded-full bg-red-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-yellow-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-green-500/70"></span>
            <span className="ml-3 text-xs text-slate-400 font-mono">example04.cpp</span>
          </div>
          <pre className="bg-slate-950 p-6 overflow-x-auto text-sm text-slate-200 font-mono leading-7"><code>{code}</code></pre>
        </div>
      </div>
    </div>
  );
}
