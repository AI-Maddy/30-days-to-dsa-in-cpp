
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

const current = "example03";

export default function Day041dArraysTwoPointersAndSlidingWindowBasicsExamples3Page() {
  const code = "/*\n * Example 3: Trapping Rain Water (1D Arrays \u2013 Two Pointers and Sliding Window basics)\n */\n// Two pointer with running max \u2014 O(n) time, O(1) space.\n#include <bits/stdc++.h>\nusing namespace std;\n\nint trap(vector<int>& h) {\n    int n = h.size(), water = 0;\n    int l=0, r=n-1, lMax=0, rMax=0;\n    while (l < r) {\n        if (h[l] < h[r]) {\n            lMax = max(lMax, h[l]);\n            water += lMax - h[l];\n            l++;\n        } else {\n            rMax = max(rMax, h[r]);\n            water += rMax - h[r];\n            r--;\n        }\n    }\n    return water;\n}\n\n// Alternative: prefix max arrays approach \u2014 O(n) time and space (easier to understand)\nint trapPrefixMax(vector<int>& h) {\n    int n = h.size();\n    vector<int> lMax(n), rMax(n);\n    lMax[0] = h[0];\n    for (int i=1;i<n;i++) lMax[i] = max(lMax[i-1], h[i]);\n    rMax[n-1] = h[n-1];\n    for (int i=n-2;i>=0;i--) rMax[i] = max(rMax[i+1], h[i]);\n    int water = 0;\n    for (int i=0;i<n;i++) water += min(lMax[i], rMax[i]) - h[i];\n    return water;\n}\n\nint main() {\n    vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};\n    cout << \"Trapped water (two-pointer): \" << trap(h) << \"\\n\";     // 6\n    cout << \"Trapped water (prefix max):  \" << trapPrefixMax(h) << \"\\n\"; // 6\n\n    vector<int> h2 = {4,2,0,3,2,5};\n    cout << \"Test 2: \" << trap(h2) << \"\\n\";  // 9\n\n    return 0;\n}\n";
  return (
    <div className="min-h-screen bg-slate-950 text-slate-100">
      <header className="sticky top-0 z-10 bg-slate-900/95 backdrop-blur border-b border-slate-800">
        <div className="max-w-6xl mx-auto px-4 py-2 flex items-center gap-2 overflow-x-auto scrollbar-hide">
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics" className={`${styles.navLink} ${styles.navHome}`}>Day 04</a>
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/README" className={`${styles.navLink} ${current === "README" ? styles.navActive + " " + styles.navReadme : styles.navReadme}`}>README</a>
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/theory" className={`${styles.navLink} ${current === "theory" ? styles.navActive + " " + styles.navTheory : styles.navTheory}`}>Theory</a>
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/examples/example01" className={`${styles.navLink} ${current === "example01" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 1</a>
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/examples/example02" className={`${styles.navLink} ${current === "example02" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 2</a>
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/examples/example03" className={`${styles.navLink} ${current === "example03" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 3</a>
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/examples/example04" className={`${styles.navLink} ${current === "example04" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 4</a>
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/examples/example05" className={`${styles.navLink} ${current === "example05" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 5</a>
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/exercises/exercise01" className={`${styles.navLink} ${current === "exercise01" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 1</a>
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/exercises/exercise02" className={`${styles.navLink} ${current === "exercise02" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 2</a>
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/exercises/exercise03" className={`${styles.navLink} ${current === "exercise03" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 3</a>
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/exercises/exercise04" className={`${styles.navLink} ${current === "exercise04" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 4</a>
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/exercises/exercise05" className={`${styles.navLink} ${current === "exercise05" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 5</a>
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/solutions/solution01" className={`${styles.navLink} ${current === "solution01" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 1</a>
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/solutions/solution02" className={`${styles.navLink} ${current === "solution02" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 2</a>
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/solutions/solution03" className={`${styles.navLink} ${current === "solution03" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 3</a>
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/solutions/solution04" className={`${styles.navLink} ${current === "solution04" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 4</a>
          <a href="/day04-1d_arrays_–_two_pointers_and_sliding_window_basics/solutions/solution05" className={`${styles.navLink} ${current === "solution05" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 5</a>
        </div>
      </header>
      <div className="max-w-6xl mx-auto px-6 pt-8 pb-16">
        <a href="/" className="text-xs text-slate-500 hover:text-slate-300 transition-colors">← Home</a>
        <div className="flex items-center gap-3 mt-3 mb-8">
          <span className="text-3xl">💡</span>
          <div>
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 04 — Example 3</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">1D Arrays – Two Pointers and Sliding Window basics</h1>
          </div>
        </div>
        <div className="rounded-xl overflow-hidden border border-slate-700">
          <div className="flex items-center gap-2 px-4 py-2.5 bg-slate-800 border-b border-slate-700">
            <span className="w-3 h-3 rounded-full bg-red-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-yellow-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-green-500/70"></span>
            <span className="ml-3 text-xs text-slate-400 font-mono">example03.cpp</span>
          </div>
          <pre className="bg-slate-950 p-6 overflow-x-auto text-sm text-slate-200 font-mono leading-7"><code>{code}</code></pre>
        </div>
      </div>
    </div>
  );
}
