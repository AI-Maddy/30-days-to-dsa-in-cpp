
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

const current = "solution04";

export default function Day09AggressiveCowsBookAllocationPaintersPartitionMedianOf2SortedArraysSolutions4Page() {
  const code = "/*\n * Solution 4: First Occurrence (BS Answer)\n */\n#include <bits/stdc++.h>\nusing namespace std;\n// Median of two sorted arrays \u2014 O(log(min(m,n)))\ndouble findMedian(vector<int>&a,vector<int>&b){\n    if(a.size()>b.size()) return findMedian(b,a);\n    int m=a.size(),n=b.size(),lo=0,hi=m;\n    while(lo<=hi){\n        int pa=lo+(hi-lo)/2,pb=(m+n+1)/2-pa;\n        int aleft=pa?a[pa-1]:INT_MIN, aright=pa<m?a[pa]:INT_MAX;\n        int bleft=pb?b[pb-1]:INT_MIN, bright=pb<n?b[pb]:INT_MAX;\n        if(aleft<=bright&&bleft<=aright){\n            if((m+n)%2) return max(aleft,bleft);\n            return(max(aleft,bleft)+min(aright,bright))/2.0;\n        }else if(aleft>bright) hi=pa-1;\n        else lo=pa+1;\n    }\n    return -1;\n}\nint main(){\n    vector<int> a={1,3},b={2};cout<<findMedian(a,b)<<\"\\n\"; // 2.0\n    vector<int> c={1,2},d={3,4};cout<<findMedian(c,d)<<\"\\n\"; // 2.5\n    return 0;\n}\n";
  return (
    <div className="min-h-screen bg-slate-950 text-slate-100">
      <header className="sticky top-0 z-10 bg-slate-900/95 backdrop-blur border-b border-slate-800">
        <div className="max-w-6xl mx-auto px-4 py-2 flex items-center gap-2 overflow-x-auto scrollbar-hide">
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays" className={`${styles.navLink} ${styles.navHome}`}>Day 09</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/README" className={`${styles.navLink} ${current === "README" ? styles.navActive + " " + styles.navReadme : styles.navReadme}`}>README</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/theory" className={`${styles.navLink} ${current === "theory" ? styles.navActive + " " + styles.navTheory : styles.navTheory}`}>Theory</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/examples/example01" className={`${styles.navLink} ${current === "example01" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 1</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/examples/example02" className={`${styles.navLink} ${current === "example02" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 2</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/examples/example03" className={`${styles.navLink} ${current === "example03" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 3</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/examples/example04" className={`${styles.navLink} ${current === "example04" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 4</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/examples/example05" className={`${styles.navLink} ${current === "example05" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 5</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/exercises/exercise01" className={`${styles.navLink} ${current === "exercise01" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 1</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/exercises/exercise02" className={`${styles.navLink} ${current === "exercise02" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 2</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/exercises/exercise03" className={`${styles.navLink} ${current === "exercise03" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 3</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/exercises/exercise04" className={`${styles.navLink} ${current === "exercise04" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 4</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/exercises/exercise05" className={`${styles.navLink} ${current === "exercise05" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 5</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/solutions/solution01" className={`${styles.navLink} ${current === "solution01" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 1</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/solutions/solution02" className={`${styles.navLink} ${current === "solution02" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 2</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/solutions/solution03" className={`${styles.navLink} ${current === "solution03" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 3</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/solutions/solution04" className={`${styles.navLink} ${current === "solution04" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 4</a>
          <a href="/day09-aggressive_cows_book_allocation_painters_partition_median_of_2_sorted_arrays/solutions/solution05" className={`${styles.navLink} ${current === "solution05" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 5</a>
        </div>
      </header>
      <div className="max-w-6xl mx-auto px-6 pt-8 pb-16">
        <a href="/" className="text-xs text-slate-500 hover:text-slate-300 transition-colors">← Home</a>
        <div className="flex items-center gap-3 mt-3 mb-8">
          <span className="text-3xl">✅</span>
          <div>
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 09 — Solution 4</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">Aggressive Cows, Book Allocation, Painters Partition, Median of 2 sorted arrays</h1>
          </div>
        </div>
        <div className="rounded-xl overflow-hidden border border-slate-700">
          <div className="flex items-center gap-2 px-4 py-2.5 bg-slate-800 border-b border-slate-700">
            <span className="w-3 h-3 rounded-full bg-red-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-yellow-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-green-500/70"></span>
            <span className="ml-3 text-xs text-slate-400 font-mono">solution04.cpp</span>
          </div>
          <pre className="bg-slate-950 p-6 overflow-x-auto text-sm text-slate-200 font-mono leading-7"><code>{code}</code></pre>
        </div>
      </div>
    </div>
  );
}
