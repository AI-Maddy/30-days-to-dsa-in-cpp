
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

export default function Day041dArraysTwoPointersAndSlidingWindowBasicsExamples1Page() {
  const code = "/*\n * Example 1: Two Sum (1D Arrays \u2013 Two Pointers and Sliding Window basics)\n */\n// Two Sum on sorted array using two pointers \u2014 O(n log n) due to sort, O(n) if pre-sorted.\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Returns indices in the ORIGINAL array that sum to target (hash map approach).\nvector<int> twoSum(vector<int>& nums, int target) {\n    unordered_map<int,int> seen;\n    for (int i = 0; i < (int)nums.size(); i++) {\n        int comp = target - nums[i];\n        if (seen.count(comp)) return {seen[comp], i};\n        seen[nums[i]] = i;\n    }\n    return {};\n}\n\n// Two pointer on sorted array \u2014 only works if we just need VALUES, not original indices.\npair<int,int> twoSumSorted(vector<int>& a, int target) {\n    int l=0, r=(int)a.size()-1;\n    while (l < r) {\n        int s = a[l]+a[r];\n        if (s==target) return {a[l], a[r]};\n        else if (s < target) l++;\n        else r--;\n    }\n    return {-1,-1};\n}\n\nint main() {\n    vector<int> nums = {2, 7, 11, 15};\n    int target = 9;\n    auto idx = twoSum(nums, target);\n    cout << \"Two Sum indices: [\" << idx[0] << \",\" << idx[1] << \"]\\n\"; // [0,1]\n\n    vector<int> sorted = {1, 2, 3, 4, 5, 6, 7, 8, 9};\n    auto [a,b] = twoSumSorted(sorted, 10);\n    cout << \"Sorted two sum: \" << a << \"+\" << b << \"=\" << (a+b) << \"\\n\"; // 1+9=10\n\n    // Find ALL pairs summing to target (two pointer)\n    vector<int> arr = {1,2,3,4,5,6,7,8,9};\n    int t = 10;\n    int lo=0, hi=(int)arr.size()-1;\n    cout << \"All pairs summing to \" << t << \": \";\n    while(lo < hi) {\n        if(arr[lo]+arr[hi]==t) { cout<<\"(\"<<arr[lo]<<\",\"<<arr[hi]<<\") \"; lo++; hi--; }\n        else if(arr[lo]+arr[hi]<t) lo++;\n        else hi--;\n    }\n    cout << \"\\n\";\n\n    return 0;\n}\n";
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
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 04 — Example 1</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">1D Arrays – Two Pointers and Sliding Window basics</h1>
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
