#!/usr/bin/env python3
"""Generate the top-level README.md from the repo day folder structure."""

from __future__ import annotations

import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def get_day_topic(day_folder: Path) -> str:
    """Extract a human-readable topic from the folder name."""
    name = day_folder.name
    # Strip "DayXX-" prefix
    match = re.match(r"Day\d+-(.*)", name)
    if not match:
        return name
    topic = match.group(1)
    # Replace underscores and decoration
    topic = topic.replace("_", " ").replace("plus", "+").replace("–", "—")
    return topic


def get_day_number(day_folder: Path) -> int:
    match = re.match(r"Day(\d+)", day_folder.name)
    return int(match.group(1)) if match else 999


def get_file_counts(day_folder: Path) -> dict[str, int]:
    counts = {}
    for sub in ("examples", "exercises", "solutions"):
        p = day_folder / sub
        counts[sub] = len(list(p.glob("*.cpp"))) if p.exists() else 0
    return counts


def build_readme() -> str:
    day_folders = sorted(
        [d for d in ROOT.iterdir() if d.is_dir() and re.match(r"Day\d+", d.name)],
        key=get_day_number,
    )

    lines = []
    lines.append("# 🚀 30 Days to DSA in C++\n")
    lines.append("![C++](https://img.shields.io/badge/Language-C%2B%2B17-blue)")
    lines.append("![Progress](https://img.shields.io/badge/Plan-30%20Days-success)")
    lines.append("![Focus](https://img.shields.io/badge/Focus-Interview%20Ready-orange)\n")
    lines.append(
        "A complete **30-day DSA journey** in C++ with daily theory, examples, exercises, and solutions.\n"
    )

    lines.append("## 🗂️ Table of Contents\n")
    lines.append("| Day | Topic | Examples | Exercises | Solutions |")
    lines.append("|-----|-------|----------|-----------|-----------|")

    for day_folder in day_folders:
        day_num = get_day_number(day_folder)
        topic = get_day_topic(day_folder)
        counts = get_file_counts(day_folder)
        rel = day_folder.relative_to(ROOT)
        lines.append(
            f"| [Day {day_num:02d}]({rel}) | {topic} "
            f"| {counts['examples']} | {counts['exercises']} | {counts['solutions']} |"
        )

    lines.append("\n## 🗂️ Repository Layout\n")
    lines.append("```")
    lines.append("30-days-to-dsa-in-cpp/")
    lines.append("├── DayXX-Topic/")
    lines.append("│   ├── README.rst        # Day overview and memory aids")
    lines.append("│   ├── theory.rst        # Detailed theory and patterns")
    lines.append("│   ├── examples/         # Reference implementations")
    lines.append("│   ├── exercises/        # Guided practice scaffolds")
    lines.append("│   └── solutions/        # Complete optimal solutions")
    lines.append("├── cheatsheets/          # Quick-reference RST files")
    lines.append("└── scripts/              # Utility scripts")
    lines.append("```\n")

    lines.append("## 🧪 Source File Standard\n")
    lines.append("Every C++ source file follows a learning template with:\n")
    lines.append("- Problem statement / goal in header comments")
    lines.append("- Pseudocode / approach notes")
    lines.append("- Clean implementation with complexity analysis")
    lines.append("- Working `main()` with sample test cases\n")

    lines.append("## 📌 Study Loop (recommended)\n")
    lines.append("1. 📖 Read `theory.rst` — understand concepts and patterns")
    lines.append("2. 👀 Study `examples/` — see clean reference implementations")
    lines.append("3. ✍️  Attempt `exercises/` — fill in guided scaffolds yourself")
    lines.append("4. ✅ Compare with `solutions/` — review and refine\n")

    lines.append("## 🛠️ Scripts\n")
    lines.append("```bash")
    lines.append("# Check repo health and compiler setup")
    lines.append("python3 scripts/setup.py")
    lines.append("")
    lines.append("# Compile and run all C++ files (or a specific day)")
    lines.append("python3 scripts/run_tests.py")
    lines.append("python3 scripts/run_tests.py --day 01")
    lines.append("")
    lines.append("# Regenerate this README")
    lines.append("python3 scripts/generate_readme.py")
    lines.append("```\n")

    lines.append(
        "> Keep this loop daily to build strong recall and interview confidence.\n"
    )

    return "\n".join(lines)


def main() -> None:
    readme_path = ROOT / "README.md"
    content = build_readme()
    readme_path.write_text(content, encoding="utf-8")
    print(f"README.md updated at {readme_path}")
    print(f"  {content.count(chr(10))} lines written.")


if __name__ == "__main__":
    main()
