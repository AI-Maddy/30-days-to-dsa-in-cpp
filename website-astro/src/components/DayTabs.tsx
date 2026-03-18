import React, { useState } from "react";
import ReactMarkdown from "react-markdown";

interface Example  { id: string; code: string }
interface Exercise { id: string; content: string }
interface Solution { id: string; code: string }

interface Props {
  readme:    string;
  theory:    string;
  examples:  Example[];
  exercises: Exercise[];
  solutions: Solution[];
}

// ── Code block with copy ──────────────────────────────────────────────────────
function CodeBlock({ code, lang = "cpp" }: { code: string; lang?: string }) {
  const [copied, setCopied] = useState(false);

  function copy() {
    navigator.clipboard.writeText(code).then(() => {
      setCopied(true);
      setTimeout(() => setCopied(false), 2000);
    });
  }

  return (
    <div className="relative group rounded-xl overflow-hidden border border-slate-700/60 my-4">
      {/* toolbar */}
      <div className="flex items-center justify-between px-4 py-2 bg-slate-900 border-b border-slate-700/60">
        <div className="flex gap-1.5">
          <span className="w-3 h-3 rounded-full bg-red-500/70" />
          <span className="w-3 h-3 rounded-full bg-yellow-500/70" />
          <span className="w-3 h-3 rounded-full bg-green-500/70" />
        </div>
        <span className="text-xs text-slate-500 font-mono">{lang}</span>
        <button
          onClick={copy}
          className="text-xs text-slate-500 hover:text-slate-200 transition-colors px-2 py-0.5 rounded border border-slate-700 hover:border-slate-500"
        >
          {copied ? "✓ copied" : "copy"}
        </button>
      </div>
      <pre className="overflow-x-auto p-5 bg-slate-950 text-sm text-slate-200 leading-6 font-mono whitespace-pre">
        <code>{code}</code>
      </pre>
    </div>
  );
}

// ── Markdown renderer ─────────────────────────────────────────────────────────
function MD({ src }: { src: string }) {
  return (
    <ReactMarkdown
      components={{
        h1: ({ children }) => <h1 className="text-2xl font-bold text-white mt-6 mb-3">{children}</h1>,
        h2: ({ children }) => <h2 className="text-xl font-bold text-slate-200 mt-5 mb-2">{children}</h2>,
        h3: ({ children }) => <h3 className="text-base font-semibold text-slate-300 mt-4 mb-2">{children}</h3>,
        p:  ({ children }) => <p className="text-slate-300 leading-7 mb-3">{children}</p>,
        ul: ({ children }) => <ul className="list-disc list-inside space-y-1 mb-3 text-slate-300">{children}</ul>,
        ol: ({ children }) => <ol className="list-decimal list-inside space-y-1 mb-3 text-slate-300">{children}</ol>,
        li: ({ children }) => <li className="text-slate-300 ml-2">{children}</li>,
        strong: ({ children }) => <strong className="text-white font-semibold">{children}</strong>,
        hr: () => <hr className="border-slate-700/60 my-4" />,
        code: ({ inline, className, children, ...rest }: any) => {
          const lang = (className ?? "").replace("language-", "") || "cpp";
          if (!inline && String(children).includes("\n")) {
            return <CodeBlock code={String(children).trimEnd()} lang={lang} />;
          }
          return <code className="bg-slate-800 text-emerald-300 px-1.5 py-0.5 rounded text-sm font-mono">{children}</code>;
        },
        pre: ({ children }) => <>{children}</>,
        blockquote: ({ children }) => (
          <div className="border-l-4 border-violet-500 bg-violet-950/30 pl-4 py-1 my-3 rounded-r-lg text-slate-300 italic text-sm">
            {children}
          </div>
        ),
      }}
    >
      {src}
    </ReactMarkdown>
  );
}

// ── Tab button ────────────────────────────────────────────────────────────────
function Tab({ active, onClick, children }: { active: boolean; onClick: () => void; children: React.ReactNode }) {
  return (
    <button
      onClick={onClick}
      className={`px-4 py-2 text-sm font-medium rounded-lg transition-colors whitespace-nowrap ${
        active
          ? "bg-slate-700 text-white"
          : "text-slate-400 hover:text-slate-200 hover:bg-slate-800"
      }`}
    >
      {children}
    </button>
  );
}

// ── Main component ────────────────────────────────────────────────────────────
type TabKey = "readme" | "theory" | "examples" | "exercises" | "solutions";

export default function DayTabs({ readme, theory, examples, exercises, solutions }: Props) {
  const [tab, setTab]     = useState<TabKey>("readme");
  const [exIdx, setExIdx] = useState(0);
  const [ezIdx, setEzIdx] = useState(0);
  const [solIdx, setSolIdx] = useState(0);

  return (
    <div>
      {/* Tab bar */}
      <div className="flex items-center gap-1 overflow-x-auto scrollbar-hide pb-1 mb-6 border-b border-slate-800">
        <Tab active={tab === "readme"}    onClick={() => setTab("readme")}>📖 README</Tab>
        <Tab active={tab === "theory"}    onClick={() => setTab("theory")}>🧠 Theory</Tab>
        <Tab active={tab === "examples"}  onClick={() => setTab("examples")}>💻 Examples <span className="ml-1 text-xs text-slate-500">{examples.length}</span></Tab>
        <Tab active={tab === "exercises"} onClick={() => setTab("exercises")}>✏️ Exercises <span className="ml-1 text-xs text-slate-500">{exercises.length}</span></Tab>
        <Tab active={tab === "solutions"} onClick={() => setTab("solutions")}>✅ Solutions <span className="ml-1 text-xs text-slate-500">{solutions.length}</span></Tab>
      </div>

      {/* README */}
      {tab === "readme" && (
        <div>
          {readme ? <MD src={readme} /> : <p className="text-slate-500 italic">No README content.</p>}
        </div>
      )}

      {/* Theory */}
      {tab === "theory" && (
        <div>
          {theory ? <MD src={theory} /> : <p className="text-slate-500 italic">No theory content.</p>}
        </div>
      )}

      {/* Examples */}
      {tab === "examples" && (
        <div>
          {examples.length === 0 ? (
            <p className="text-slate-500 italic">No examples.</p>
          ) : (
            <>
              <div className="flex gap-2 mb-4 flex-wrap">
                {examples.map((ex, i) => (
                  <button
                    key={ex.id}
                    onClick={() => setExIdx(i)}
                    className={`px-3 py-1 text-xs rounded-lg font-mono transition-colors ${
                      i === exIdx
                        ? "bg-emerald-600 text-white"
                        : "bg-slate-800 text-slate-400 hover:bg-slate-700 hover:text-slate-200"
                    }`}
                  >
                    {ex.id}
                  </button>
                ))}
              </div>
              <CodeBlock code={examples[exIdx]?.code || ""} />
            </>
          )}
        </div>
      )}

      {/* Exercises */}
      {tab === "exercises" && (
        <div>
          {exercises.length === 0 ? (
            <p className="text-slate-500 italic">No exercises.</p>
          ) : (
            <>
              <div className="flex gap-2 mb-4 flex-wrap">
                {exercises.map((ez, i) => (
                  <button
                    key={ez.id}
                    onClick={() => setEzIdx(i)}
                    className={`px-3 py-1 text-xs rounded-lg font-mono transition-colors ${
                      i === ezIdx
                        ? "bg-amber-600 text-white"
                        : "bg-slate-800 text-slate-400 hover:bg-slate-700 hover:text-slate-200"
                    }`}
                  >
                    {ez.id}
                  </button>
                ))}
              </div>
              <div className="bg-amber-950/20 border border-amber-500/20 rounded-xl p-5">
                <MD src={exercises[ezIdx]?.content || ""} />
              </div>
            </>
          )}
        </div>
      )}

      {/* Solutions */}
      {tab === "solutions" && (
        <div>
          {solutions.length === 0 ? (
            <p className="text-slate-500 italic">No solutions.</p>
          ) : (
            <>
              <div className="flex gap-2 mb-4 flex-wrap">
                {solutions.map((sol, i) => (
                  <button
                    key={sol.id}
                    onClick={() => setSolIdx(i)}
                    className={`px-3 py-1 text-xs rounded-lg font-mono transition-colors ${
                      i === solIdx
                        ? "bg-green-600 text-white"
                        : "bg-slate-800 text-slate-400 hover:bg-slate-700 hover:text-slate-200"
                    }`}
                  >
                    {sol.id}
                  </button>
                ))}
              </div>
              <CodeBlock code={solutions[solIdx]?.code || ""} />
            </>
          )}
        </div>
      )}
    </div>
  );
}
