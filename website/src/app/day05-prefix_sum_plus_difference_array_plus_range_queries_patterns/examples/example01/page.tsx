
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

const current = "example01";

export default function Day05PrefixSumPlusDifferenceArrayPlusRangeQueriesPatternsExamples1Page() {
  const code = "/*\n * Example 1: Prefix Sum Query (Prefix Sum plus Difference Array plus Range queries patterns)\n */\n#include <bits/stdc++.h>\nusing namespace std;\nint main() {\n    vector<int> a = {3,1,4,1,5,9,2,6,5,3};\n    int n = a.size();\n    // Build prefix sum array: pre[i] = a[0]+...+a[i-1]\n    vector<int> pre(n+1, 0);\n    for (int i=0;i<n;i++) pre[i+1]=pre[i]+a[i];\n    // Range sum [l,r] in O(1): pre[r+1] - pre[l]\n    cout << \"Array: \"; for(int x:a) cout<<x<<\" \"; cout<<\"\\n\";\n    cout << \"Sum [0,4] = \" << pre[5]-pre[0] << \"  (expected 14)\\n\";\n    cout << \"Sum [2,7] = \" << pre[8]-pre[2] << \"  (expected 26)\\n\";\n    // Count queries answered in O(1) after O(n) preprocessing\n    int Q = 5;\n    vector<pair<int,int>> queries = {{0,9},{1,5},{3,6},{0,0},{9,9}};\n    for(auto[l,r]:queries)\n        cout << \"Sum[\" << l << \",\" << r << \"] = \" << pre[r+1]-pre[l] << \"\\n\";\n    return 0;\n}\n";
  return (
    <div className="min-h-screen bg-slate-950 text-slate-100">
      <header className="sticky top-0 z-10 bg-slate-900/95 backdrop-blur border-b border-slate-800">
        <div className="max-w-6xl mx-auto px-4 py-2 flex items-center gap-2 overflow-x-auto scrollbar-hide">
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns" className={`${styles.navLink} ${styles.navHome}`}>Day 05</a>
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns/README" className={`${styles.navLink} ${current === "README" ? styles.navActive + " " + styles.navReadme : styles.navReadme}`}>README</a>
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns/theory" className={`${styles.navLink} ${current === "theory" ? styles.navActive + " " + styles.navTheory : styles.navTheory}`}>Theory</a>
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns/examples/example01" className={`${styles.navLink} ${current === "example01" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 1</a>
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns/examples/example02" className={`${styles.navLink} ${current === "example02" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 2</a>
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns/examples/example03" className={`${styles.navLink} ${current === "example03" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 3</a>
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns/examples/example04" className={`${styles.navLink} ${current === "example04" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 4</a>
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns/examples/example05" className={`${styles.navLink} ${current === "example05" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 5</a>
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns/exercises/exercise01" className={`${styles.navLink} ${current === "exercise01" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 1</a>
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns/exercises/exercise02" className={`${styles.navLink} ${current === "exercise02" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 2</a>
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns/exercises/exercise03" className={`${styles.navLink} ${current === "exercise03" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 3</a>
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns/exercises/exercise04" className={`${styles.navLink} ${current === "exercise04" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 4</a>
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns/exercises/exercise05" className={`${styles.navLink} ${current === "exercise05" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 5</a>
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns/solutions/solution01" className={`${styles.navLink} ${current === "solution01" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 1</a>
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns/solutions/solution02" className={`${styles.navLink} ${current === "solution02" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 2</a>
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns/solutions/solution03" className={`${styles.navLink} ${current === "solution03" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 3</a>
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns/solutions/solution04" className={`${styles.navLink} ${current === "solution04" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 4</a>
          <a href="/day05-prefix_sum_plus_difference_array_plus_range_queries_patterns/solutions/solution05" className={`${styles.navLink} ${current === "solution05" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 5</a>
        </div>
      </header>
      <div className="max-w-6xl mx-auto px-6 pt-8 pb-16">
        <a href="/" className="text-xs text-slate-500 hover:text-slate-300 transition-colors">← Home</a>
        <div className="flex items-center gap-3 mt-3 mb-8">
          <span className="text-3xl">💡</span>
          <div>
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 05 — Example 1</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">Prefix Sum plus Difference Array plus Range queries patterns</h1>
          </div>
        </div>
        <div className="rounded-xl overflow-hidden border border-slate-700">
          <div className="flex items-center gap-2 px-4 py-2.5 bg-slate-800 border-b border-slate-700">
            <span className="w-3 h-3 rounded-full bg-red-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-yellow-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-green-500/70"></span>
            <span className="ml-3 text-xs text-slate-400 font-mono">example01.cpp</span>
          </div>
          <pre className="bg-slate-950 p-6 overflow-x-auto text-sm text-slate-200 font-mono leading-7"><code>{code}</code></pre>
        </div>
      </div>
    </div>
  );
}
