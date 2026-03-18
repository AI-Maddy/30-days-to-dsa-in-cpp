import React, { useState } from "react";
import ReactMarkdown from "react-markdown";

interface Props {
  content: string;
}

function CopyableCode({ code, lang }: { code: string; lang: string }) {
  const [copied, setCopied] = useState(false);
  function copy() {
    navigator.clipboard.writeText(code).then(() => {
      setCopied(true);
      setTimeout(() => setCopied(false), 2000);
    });
  }
  return (
    <div className="relative group rounded-xl overflow-hidden border border-slate-700/60 my-3">
      <div className="flex items-center justify-between px-4 py-1.5 bg-slate-900 border-b border-slate-700/60">
        <div className="flex gap-1.5">
          <span className="w-2.5 h-2.5 rounded-full bg-red-500/60" />
          <span className="w-2.5 h-2.5 rounded-full bg-yellow-500/60" />
          <span className="w-2.5 h-2.5 rounded-full bg-green-500/60" />
        </div>
        <span className="text-xs text-slate-500 font-mono">{lang}</span>
        <button
          onClick={copy}
          className="text-xs text-slate-500 hover:text-slate-200 transition-colors px-2 py-0.5 rounded border border-slate-700 hover:border-slate-500"
        >
          {copied ? "✓" : "copy"}
        </button>
      </div>
      <pre className="overflow-x-auto p-4 bg-slate-950 text-sm text-slate-200 leading-6 font-mono whitespace-pre">
        <code>{code}</code>
      </pre>
    </div>
  );
}

export default function CheatsheetView({ content }: Props) {
  return (
    <ReactMarkdown
      components={{
        h1: ({ children }) => <h1 className="text-2xl font-extrabold text-white mb-4 mt-2">{children}</h1>,
        h2: ({ children }) => <h2 className="text-lg font-bold text-violet-300 mt-6 mb-2 pb-1 border-b border-slate-800">{children}</h2>,
        h3: ({ children }) => <h3 className="text-base font-semibold text-slate-200 mt-4 mb-2">{children}</h3>,
        p:  ({ children }) => <p className="text-slate-300 leading-7 mb-3">{children}</p>,
        ul: ({ children }) => <ul className="list-disc list-inside space-y-1 mb-3 text-slate-300">{children}</ul>,
        ol: ({ children }) => <ol className="list-decimal list-inside space-y-1 mb-3 text-slate-300">{children}</ol>,
        li: ({ children }) => <li className="text-slate-300 ml-2">{children}</li>,
        strong: ({ children }) => <strong className="text-white font-semibold">{children}</strong>,
        hr: () => <hr className="border-slate-700/60 my-4" />,
        blockquote: ({ children }) => (
          <div className="border-l-4 border-violet-500 bg-violet-950/30 pl-4 py-2 my-3 rounded-r-lg text-sm text-violet-200 italic">
            {children}
          </div>
        ),
        code: ({ inline, className, children, ...rest }: any) => {
          const lang = (className ?? "").replace("language-", "") || "cpp";
          if (!inline && String(children).includes("\n")) {
            return <CopyableCode code={String(children).trimEnd()} lang={lang} />;
          }
          return <code className="bg-slate-800 text-emerald-300 px-1.5 py-0.5 rounded text-sm font-mono">{children}</code>;
        },
        pre: ({ children }) => <>{children}</>,
      }}
    >
      {content}
    </ReactMarkdown>
  );
}
