
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

const current = "example05";

export default function Day301dDpPatternsMiniRevisionMixedMediumHardExamples5Page() {
  const code = "/*\n * Example 5: Edit Distance LCS\n */\n#include <bits/stdc++.h>\nusing namespace std;\n// Example 5: Edit Distance (Levenshtein Distance) + LCS\nint editDistance(const string& a, const string& b) {\n    int m = a.size(), n = b.size();\n    vector<vector<int>> dp(m+1, vector<int>(n+1));\n    for (int i=0;i<=m;i++) dp[i][0]=i;\n    for (int j=0;j<=n;j++) dp[0][j]=j;\n    for (int i=1;i<=m;i++)\n        for (int j=1;j<=n;j++) {\n            if (a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];\n            else dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});\n        }\n    return dp[m][n];\n}\nint lcs(const string& a, const string& b) {\n    int m=a.size(), n=b.size();\n    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));\n    for (int i=1;i<=m;i++)\n        for (int j=1;j<=n;j++)\n            dp[i][j] = (a[i-1]==b[j-1]) ? dp[i-1][j-1]+1 : max(dp[i-1][j],dp[i][j-1]);\n    return dp[m][n];\n}\nint main() {\n    cout << editDistance(\"horse\",\"ros\") << \"\\n\"; // 3\n    cout << lcs(\"ABCBDAB\",\"BDCAB\") << \"\\n\";      // 4\n}\n";
  return (
    <div className="min-h-screen bg-slate-950 text-slate-100">
      <header className="sticky top-0 z-10 bg-slate-900/95 backdrop-blur border-b border-slate-800">
        <div className="max-w-6xl mx-auto px-4 py-2 flex items-center gap-2 overflow-x-auto scrollbar-hide">
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard" className={`${styles.navLink} ${styles.navHome}`}>Day 30</a>
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard/README" className={`${styles.navLink} ${current === "README" ? styles.navActive + " " + styles.navReadme : styles.navReadme}`}>README</a>
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard/theory" className={`${styles.navLink} ${current === "theory" ? styles.navActive + " " + styles.navTheory : styles.navTheory}`}>Theory</a>
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard/examples/example01" className={`${styles.navLink} ${current === "example01" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 1</a>
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard/examples/example02" className={`${styles.navLink} ${current === "example02" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 2</a>
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard/examples/example03" className={`${styles.navLink} ${current === "example03" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 3</a>
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard/examples/example04" className={`${styles.navLink} ${current === "example04" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 4</a>
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard/examples/example05" className={`${styles.navLink} ${current === "example05" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 5</a>
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard/exercises/exercise01" className={`${styles.navLink} ${current === "exercise01" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 1</a>
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard/exercises/exercise02" className={`${styles.navLink} ${current === "exercise02" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 2</a>
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard/exercises/exercise03" className={`${styles.navLink} ${current === "exercise03" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 3</a>
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard/exercises/exercise04" className={`${styles.navLink} ${current === "exercise04" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 4</a>
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard/exercises/exercise05" className={`${styles.navLink} ${current === "exercise05" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 5</a>
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard/solutions/solution01" className={`${styles.navLink} ${current === "solution01" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 1</a>
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard/solutions/solution02" className={`${styles.navLink} ${current === "solution02" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 2</a>
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard/solutions/solution03" className={`${styles.navLink} ${current === "solution03" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 3</a>
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard/solutions/solution04" className={`${styles.navLink} ${current === "solution04" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 4</a>
          <a href="/day30-1d_dp_patterns_mini_revision_mixed_medium_hard/solutions/solution05" className={`${styles.navLink} ${current === "solution05" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 5</a>
        </div>
      </header>
      <div className="max-w-6xl mx-auto px-6 pt-8 pb-16">
        <a href="/" className="text-xs text-slate-500 hover:text-slate-300 transition-colors">← Home</a>
        <div className="flex items-center gap-3 mt-3 mb-8">
          <span className="text-3xl">💡</span>
          <div>
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 30 — Example 5</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">1D DP patterns plus Mini revision plus Solve mixed medium hard problems</h1>
          </div>
        </div>
        <div className="rounded-xl overflow-hidden border border-slate-700">
          <div className="flex items-center gap-2 px-4 py-2.5 bg-slate-800 border-b border-slate-700">
            <span className="w-3 h-3 rounded-full bg-red-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-yellow-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-green-500/70"></span>
            <span className="ml-3 text-xs text-slate-400 font-mono">example05.cpp</span>
          </div>
          <pre className="bg-slate-950 p-6 overflow-x-auto text-sm text-slate-200 font-mono leading-7"><code>{code}</code></pre>
        </div>
      </div>
    </div>
  );
}
