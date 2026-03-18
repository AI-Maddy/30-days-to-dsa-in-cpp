
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

const current = "theory";

export default function Day03BitManipulationInCplusplusTheoryPage() {
  const content = "---\n\n# **Day 3 \u2013 THEORY.rst**  \n## **\u26a1 Bit Manipulation in C++ \u2013 Mastering Bits, Masks, Tricks & Patterns**\n\n---\n\n# **\ud83c\udf1f 1. Overview**\n\nBit manipulation is one of the most **powerful**, **beautiful**, and **high\u2011performance** techniques in programming.\n\nIt gives you:\n\n- \u26a1 Constant\u2011time operations  \n- \ud83e\udde0 Elegant mathematical tricks  \n- \ud83c\udfaf Perfect solutions for XOR, subsets, masks  \n- \ud83d\ude80 Competitive\u2011programming\u2011level speed  \n\nMastering bits makes you a **10\u00d7 better problem solver**.\n\n---\n\n# **\ud83d\udd22 2. Binary Representation Refresher**\n\nEvery integer is stored in **binary**:\n\n```\n13 \u2192 1101\n7  \u2192 0111\n```\n\nEach bit represents a power of 2:\n\n```\nbit0 = 1\nbit1 = 2\nbit2 = 4\nbit3 = 8\n...\n```\n\n---\n\n# **\ud83e\uddf0 3. Bitwise Operators (The Core Tools)**\n\n| Operator | Symbol | Meaning |\n|----------|--------|---------|\n| AND | `&` | bitwise AND |\n| OR | `\\|` | bitwise OR |\n| XOR | `^` | bitwise XOR |\n| NOT | `~` | bitwise NOT |\n| Left Shift | `<<` | multiply by 2 |\n| Right Shift | `>>` | divide by 2 |\n\n---\n\n## **\ud83d\udfe6 3.1 AND `&`**\n\n```\n1 & 1 = 1\n1 & 0 = 0\n```\n\nUsed for:\n\n- Checking if a bit is set  \n- Masking  \n\n---\n\n## **\ud83d\udfe9 3.2 OR `|`**\n\n```\n1 | 0 = 1\n```\n\nUsed for:\n\n- Setting a bit  \n\n---\n\n## **\ud83d\udfe8 3.3 XOR `^`**\n\n```\n1 ^ 1 = 0\n1 ^ 0 = 1\n```\n\nProperties:\n\n- `x ^ x = 0`  \n- `x ^ 0 = x`  \n- XOR is reversible  \n\nUsed in:\n\n- Single number problems  \n- Swapping without temp  \n\n---\n\n## **\ud83d\udfe7 3.4 NOT `~`**\n\nFlips all bits.\n\n---\n\n## **\ud83d\udfe5 3.5 Left Shift `<<`**\n\n```\nx << 1 = x * 2\n```\n\n---\n\n## **\ud83d\udfea 3.6 Right Shift `>>`**\n\n```\nx >> 1 = x / 2\n```\n\n---\n\n# **\ud83c\udfaf 4. Bit Masks (The Heart of Bit Manipulation)**\n\nA **bit mask** is a number used to manipulate specific bits.\n\n---\n\n## **\ud83d\udfe6 4.1 Check if a bit is set**\n\n```\nif (n & (1 << k))\n```\n\n---\n\n## **\ud83d\udfe9 4.2 Set a bit**\n\n```\nn | (1 << k)\n```\n\n---\n\n## **\ud83d\udfe8 4.3 Clear a bit**\n\n```\nn & ~(1 << k)\n```\n\n---\n\n## **\ud83d\udfe7 4.4 Toggle a bit**\n\n```\nn ^ (1 << k)\n```\n\n---\n\n## **\ud83d\udfe5 4.5 Extract last set bit**\n\n```\nn & -n\n```\n\nUsed in:\n\n- Fenwick Tree  \n- Subset generation  \n\n---\n\n# **\ud83e\udde0 5. Important Bit Tricks (Must Memorize)**\n\n---\n\n## **\ud83d\udd25 Trick 1 \u2014 Check if number is power of 2**\n\n```\nn & (n - 1) == 0\n```\n\n---\n\n## **\ud83d\udd25 Trick 2 \u2014 Count set bits (Brian Kernighan)**\n\n```\nwhile (n) {\n    n &= (n - 1);\n    count++;\n}\n```\n\n---\n\n## **\ud83d\udd25 Trick 3 \u2014 Swap without temp**\n\n```\na ^= b;\nb ^= a;\na ^= b;\n```\n\n---\n\n## **\ud83d\udd25 Trick 4 \u2014 Turn off rightmost set bit**\n\n```\nn & (n - 1)\n```\n\n---\n\n## **\ud83d\udd25 Trick 5 \u2014 Get rightmost set bit**\n\n```\nn & -n\n```\n\n---\n\n# **\ud83e\udde9 6. XOR Patterns (Extremely Important)**\n\n---\n\n## **\ud83d\udfe6 6.1 Find unique element (all others appear twice)**\n\n```\nans = 0\nfor x in array:\n    ans ^= x\n```\n\n---\n\n## **\ud83d\udfe9 6.2 Find two unique elements**\n\nUse XOR + rightmost set bit trick.\n\n---\n\n## **\ud83d\udfe8 6.3 XOR prefix trick**\n\nUsed in:\n\n- Subarray XOR  \n- Range XOR queries  \n\n---\n\n# **\ud83e\uddee 7. Bit Manipulation in C++**\n\n---\n\n## **\ud83d\udfe6 7.1 Built\u2011in functions**\n\n### **Count set bits**\n\n```\n__builtin_popcount(x)\n__builtin_popcountll(x)\n```\n\n### **Count leading zeros**\n\n```\n__builtin_clz(x)\n```\n\n### **Count trailing zeros**\n\n```\n__builtin_ctz(x)\n```\n\n---\n\n# **\ud83e\uddf1 8. Subset Generation Using Bits**\n\nFor array of size `n`, subsets = `2^n`.\n\n```\nfor (int mask = 0; mask < (1 << n); mask++) {\n    for (int i = 0; i < n; i++) {\n        if (mask & (1 << i))\n            include element i\n    }\n}\n```\n\nUsed in:\n\n- Backtracking  \n- DP on subsets  \n- Combinatorics  \n\n---\n\n# **\ud83d\udcd8 9. Bit Manipulation Patterns in Interviews**\n\n---\n\n## **Pattern 1 \u2014 XOR for uniqueness**\n\nUsed in:\n\n- Single number  \n- Missing number  \n- Duplicate detection  \n\n---\n\n## **Pattern 2 \u2014 Bitmask DP**\n\nUsed in:\n\n- Traveling Salesman  \n- Subset DP  \n- Word masks  \n\n---\n\n## **Pattern 3 \u2014 Using bits for state compression**\n\nUsed in:\n\n- Graph problems  \n- DP optimization  \n\n---\n\n## **Pattern 4 \u2014 Using shifts for fast multiplication/division**\n\n---\n\n# **\ud83c\udfaf 10. Interview\u2011Level Insights**\n\n- Bit manipulation is **constant time**  \n- XOR is your best friend  \n- Masks simplify complex logic  \n- Built\u2011ins make code faster  \n- Subset generation is easiest with bits  \n\n---\n\n# **\ud83c\udfc1 11. Conclusion**\n\nDay 3 gives you mastery over:\n\n- Bitwise operators  \n- Masks  \n- XOR tricks  \n- Built\u2011ins  \n- Subset generation  \n- Interview patterns  \n\nThis knowledge becomes essential for:\n\n- DP  \n- Graphs  \n- Backtracking  \n- Optimization problems  \n\nYou now have the **bit\u2011level superpowers** needed for advanced DSA.\n";
  return (
    <div className="min-h-screen bg-slate-950 text-slate-100">
      <header className="sticky top-0 z-10 bg-slate-900/95 backdrop-blur border-b border-slate-800">
        <div className="max-w-6xl mx-auto px-4 py-2 flex items-center gap-2 overflow-x-auto scrollbar-hide">
          <a href="/day03-bit_manipulation_in_cplusplus" className={`${styles.navLink} ${styles.navHome}`}>Day 03</a>
          <a href="/day03-bit_manipulation_in_cplusplus/README" className={`${styles.navLink} ${current === "README" ? styles.navActive + " " + styles.navReadme : styles.navReadme}`}>README</a>
          <a href="/day03-bit_manipulation_in_cplusplus/theory" className={`${styles.navLink} ${current === "theory" ? styles.navActive + " " + styles.navTheory : styles.navTheory}`}>Theory</a>
          <a href="/day03-bit_manipulation_in_cplusplus/examples/example01" className={`${styles.navLink} ${current === "example01" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 1</a>
          <a href="/day03-bit_manipulation_in_cplusplus/examples/example02" className={`${styles.navLink} ${current === "example02" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 2</a>
          <a href="/day03-bit_manipulation_in_cplusplus/examples/example03" className={`${styles.navLink} ${current === "example03" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 3</a>
          <a href="/day03-bit_manipulation_in_cplusplus/examples/example04" className={`${styles.navLink} ${current === "example04" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 4</a>
          <a href="/day03-bit_manipulation_in_cplusplus/examples/example05" className={`${styles.navLink} ${current === "example05" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 5</a>
          <a href="/day03-bit_manipulation_in_cplusplus/exercises/exercise01" className={`${styles.navLink} ${current === "exercise01" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 1</a>
          <a href="/day03-bit_manipulation_in_cplusplus/exercises/exercise02" className={`${styles.navLink} ${current === "exercise02" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 2</a>
          <a href="/day03-bit_manipulation_in_cplusplus/exercises/exercise03" className={`${styles.navLink} ${current === "exercise03" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 3</a>
          <a href="/day03-bit_manipulation_in_cplusplus/exercises/exercise04" className={`${styles.navLink} ${current === "exercise04" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 4</a>
          <a href="/day03-bit_manipulation_in_cplusplus/exercises/exercise05" className={`${styles.navLink} ${current === "exercise05" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 5</a>
          <a href="/day03-bit_manipulation_in_cplusplus/solutions/solution01" className={`${styles.navLink} ${current === "solution01" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 1</a>
          <a href="/day03-bit_manipulation_in_cplusplus/solutions/solution02" className={`${styles.navLink} ${current === "solution02" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 2</a>
          <a href="/day03-bit_manipulation_in_cplusplus/solutions/solution03" className={`${styles.navLink} ${current === "solution03" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 3</a>
          <a href="/day03-bit_manipulation_in_cplusplus/solutions/solution04" className={`${styles.navLink} ${current === "solution04" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 4</a>
          <a href="/day03-bit_manipulation_in_cplusplus/solutions/solution05" className={`${styles.navLink} ${current === "solution05" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 5</a>
        </div>
      </header>
      <div className="max-w-6xl mx-auto px-6 pt-8 pb-16">
        <a href="/" className="text-xs text-slate-500 hover:text-slate-300 transition-colors">← Home</a>
        <div className="flex items-center gap-3 mt-3 mb-8">
          <span className="text-3xl">🧠</span>
          <div>
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 03 — theory</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">Bit Manipulation in Cplusplus</h1>
          </div>
        </div>
        <pre className="bg-slate-900 border border-slate-700/60 rounded-xl p-6 overflow-x-auto text-sm text-slate-200 whitespace-pre-wrap leading-7 font-mono">{content}</pre>
      </div>
    </div>
  );
}
