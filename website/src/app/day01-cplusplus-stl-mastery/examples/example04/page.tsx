
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

export default function Day01CplusplusStlMasteryExamples4Page() {
  const code = "/*\n * Example 4: Deque Operations (Cplusplus STL Mastery)\n */\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    // deque supports O(1) push/pop at both ends\n    deque<int> dq;\n    dq.push_back(3);  dq.push_back(4);  dq.push_back(5);\n    dq.push_front(2); dq.push_front(1);\n    cout << \"deque (front to back): \";\n    for (int x : dq) cout << x << \" \"; cout << \"\\n\";\n\n    cout << \"front=\" << dq.front() << \"  back=\" << dq.back() << \"\\n\";\n    dq.pop_front(); dq.pop_back();\n    cout << \"After pop_front + pop_back: \";\n    for (int x : dq) cout << x << \" \"; cout << \"\\n\";\n\n    // Classic use: Sliding Window Maximum using monotonic deque\n    // Window of size k \u2014 deque stores indices, front = index of max\n    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};\n    int k = 3;\n    deque<int> mono;  // stores indices\n    vector<int> result;\n\n    for (int i = 0; i < (int)nums.size(); i++) {\n        // Remove indices outside window\n        while (!mono.empty() && mono.front() < i - k + 1)\n            mono.pop_front();\n        // Maintain decreasing order: remove smaller elements from back\n        while (!mono.empty() && nums[mono.back()] <= nums[i])\n            mono.pop_back();\n        mono.push_back(i);\n        // Window has k elements starting from index k-1\n        if (i >= k - 1)\n            result.push_back(nums[mono.front()]);\n    }\n\n    cout << \"\\nSliding Window Max (k=\" << k << \"):\\n\";\n    cout << \"Input:  \"; for (int x : nums)   cout << x << \" \"; cout << \"\\n\";\n    cout << \"Output: \"; for (int x : result) cout << x << \" \"; cout << \"\\n\";\n\n    return 0;\n}\n";
  return (
    <div className="min-h-screen bg-slate-950 text-slate-100">
      <header className="sticky top-0 z-10 bg-slate-900/95 backdrop-blur border-b border-slate-800">
        <div className="max-w-6xl mx-auto px-4 py-2 flex items-center gap-2 overflow-x-auto scrollbar-hide">
          <a href="/day01-cplusplus-stl-mastery" className={`${styles.navLink} ${styles.navHome}`}>Day 01</a>
          <a href="/day01-cplusplus-stl-mastery/README" className={`${styles.navLink} ${current === "README" ? styles.navActive + " " + styles.navReadme : styles.navReadme}`}>README</a>
          <a href="/day01-cplusplus-stl-mastery/theory" className={`${styles.navLink} ${current === "theory" ? styles.navActive + " " + styles.navTheory : styles.navTheory}`}>Theory</a>
          <a href="/day01-cplusplus-stl-mastery/examples/example01" className={`${styles.navLink} ${current === "example01" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 1</a>
          <a href="/day01-cplusplus-stl-mastery/examples/example02" className={`${styles.navLink} ${current === "example02" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 2</a>
          <a href="/day01-cplusplus-stl-mastery/examples/example03" className={`${styles.navLink} ${current === "example03" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 3</a>
          <a href="/day01-cplusplus-stl-mastery/examples/example04" className={`${styles.navLink} ${current === "example04" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 4</a>
          <a href="/day01-cplusplus-stl-mastery/examples/example05" className={`${styles.navLink} ${current === "example05" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 5</a>
          <a href="/day01-cplusplus-stl-mastery/exercises/exercise01" className={`${styles.navLink} ${current === "exercise01" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 1</a>
          <a href="/day01-cplusplus-stl-mastery/exercises/exercise02" className={`${styles.navLink} ${current === "exercise02" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 2</a>
          <a href="/day01-cplusplus-stl-mastery/exercises/exercise03" className={`${styles.navLink} ${current === "exercise03" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 3</a>
          <a href="/day01-cplusplus-stl-mastery/exercises/exercise04" className={`${styles.navLink} ${current === "exercise04" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 4</a>
          <a href="/day01-cplusplus-stl-mastery/exercises/exercise05" className={`${styles.navLink} ${current === "exercise05" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 5</a>
          <a href="/day01-cplusplus-stl-mastery/solutions/solution01" className={`${styles.navLink} ${current === "solution01" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 1</a>
          <a href="/day01-cplusplus-stl-mastery/solutions/solution02" className={`${styles.navLink} ${current === "solution02" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 2</a>
          <a href="/day01-cplusplus-stl-mastery/solutions/solution03" className={`${styles.navLink} ${current === "solution03" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 3</a>
          <a href="/day01-cplusplus-stl-mastery/solutions/solution04" className={`${styles.navLink} ${current === "solution04" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 4</a>
          <a href="/day01-cplusplus-stl-mastery/solutions/solution05" className={`${styles.navLink} ${current === "solution05" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 5</a>
        </div>
      </header>
      <div className="max-w-6xl mx-auto px-6 pt-8 pb-16">
        <a href="/" className="text-xs text-slate-500 hover:text-slate-300 transition-colors">← Home</a>
        <div className="flex items-center gap-3 mt-3 mb-8">
          <span className="text-3xl">💡</span>
          <div>
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 01 — Example 4</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">Cplusplus STL Mastery</h1>
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
