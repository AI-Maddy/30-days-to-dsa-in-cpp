
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

const current = "solution03";

export default function Day25NQueensSudokuSolverWordSearchRatInMazeSolutions3Page() {
  const code = "/*\n * Solution 3: Sudoku Solver\n */\n#include <bits/stdc++.h>\nusing namespace std;\nbool isValid(vector<vector<char>>&b,int r,int c,char ch){\n    for(int i=0;i<9;i++){\n        if(b[r][i]==ch||b[i][c]==ch||b[3*(r/3)+i/3][3*(c/3)+i%3]==ch)return false;\n    }return true;\n}\nbool solveSudoku(vector<vector<char>>&b){\n    for(int r=0;r<9;r++)for(int c=0;c<9;c++)if(b[r][c]=='.'){\n        for(char ch='1';ch<='9';ch++){\n            if(isValid(b,r,c,ch)){b[r][c]=ch;if(solveSudoku(b))return true;b[r][c]='.';}\n        }return false;\n    }return true;\n}\nint main(){ios::sync_with_stdio(false);cin.tie(nullptr);\n    vector<vector<char>>board={\n        {'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},\n        {'.','9','8','.','.','.','.','6','.'},{'.','.','.','.','.','.','.','.','.'},\n        {'8','.','.','.','6','.','.','.','3'},{'.','.','.','.','2','.','.','.','.'},\n        {'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},\n        {'.','.','.','.','8','.','.','7','9'}\n    };\n    solveSudoku(board);\n    for(auto&row:board){for(char c:row)cout<<c<<\" \";cout<<\"\\n\";}\n}\n";
  return (
    <div className="min-h-screen bg-slate-950 text-slate-100">
      <header className="sticky top-0 z-10 bg-slate-900/95 backdrop-blur border-b border-slate-800">
        <div className="max-w-6xl mx-auto px-4 py-2 flex items-center gap-2 overflow-x-auto scrollbar-hide">
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze" className={`${styles.navLink} ${styles.navHome}`}>Day 25</a>
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze/README" className={`${styles.navLink} ${current === "README" ? styles.navActive + " " + styles.navReadme : styles.navReadme}`}>README</a>
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze/theory" className={`${styles.navLink} ${current === "theory" ? styles.navActive + " " + styles.navTheory : styles.navTheory}`}>Theory</a>
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze/examples/example01" className={`${styles.navLink} ${current === "example01" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 1</a>
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze/examples/example02" className={`${styles.navLink} ${current === "example02" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 2</a>
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze/examples/example03" className={`${styles.navLink} ${current === "example03" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 3</a>
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze/examples/example04" className={`${styles.navLink} ${current === "example04" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 4</a>
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze/examples/example05" className={`${styles.navLink} ${current === "example05" ? styles.navActive + " " + styles.navExample : styles.navExample}`}>Ex 5</a>
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze/exercises/exercise01" className={`${styles.navLink} ${current === "exercise01" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 1</a>
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze/exercises/exercise02" className={`${styles.navLink} ${current === "exercise02" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 2</a>
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze/exercises/exercise03" className={`${styles.navLink} ${current === "exercise03" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 3</a>
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze/exercises/exercise04" className={`${styles.navLink} ${current === "exercise04" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 4</a>
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze/exercises/exercise05" className={`${styles.navLink} ${current === "exercise05" ? styles.navActive + " " + styles.navExercise : styles.navExercise}`}>P 5</a>
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze/solutions/solution01" className={`${styles.navLink} ${current === "solution01" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 1</a>
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze/solutions/solution02" className={`${styles.navLink} ${current === "solution02" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 2</a>
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze/solutions/solution03" className={`${styles.navLink} ${current === "solution03" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 3</a>
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze/solutions/solution04" className={`${styles.navLink} ${current === "solution04" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 4</a>
          <a href="/day25-n_queens_sudoku_solver_word_search_rat_in_maze/solutions/solution05" className={`${styles.navLink} ${current === "solution05" ? styles.navActive + " " + styles.navSolution : styles.navSolution}`}>Sol 5</a>
        </div>
      </header>
      <div className="max-w-6xl mx-auto px-6 pt-8 pb-16">
        <a href="/" className="text-xs text-slate-500 hover:text-slate-300 transition-colors">← Home</a>
        <div className="flex items-center gap-3 mt-3 mb-8">
          <span className="text-3xl">✅</span>
          <div>
            <div className="text-xs text-slate-500 uppercase tracking-widest">Day 25 — Solution 3</div>
            <h1 className="text-xl font-bold text-slate-100 mt-0.5">N Queens, Sudoku Solver, Word Search, Rat in Maze</h1>
          </div>
        </div>
        <div className="rounded-xl overflow-hidden border border-slate-700">
          <div className="flex items-center gap-2 px-4 py-2.5 bg-slate-800 border-b border-slate-700">
            <span className="w-3 h-3 rounded-full bg-red-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-yellow-500/70"></span>
            <span className="w-3 h-3 rounded-full bg-green-500/70"></span>
            <span className="ml-3 text-xs text-slate-400 font-mono">solution03.cpp</span>
          </div>
          <pre className="bg-slate-950 p-6 overflow-x-auto text-sm text-slate-200 font-mono leading-7"><code>{code}</code></pre>
        </div>
      </div>
    </div>
  );
}
