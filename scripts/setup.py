#!/usr/bin/env python3
"""Health check: verify compiler, Python version, and repo structure."""

from __future__ import annotations

import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

EXPECTED_DAYS = 30
EXPECTED_SUBFOLDERS = ("examples", "exercises", "solutions")
EXPECTED_FILES_PER_FOLDER = 5
REQUIRED_DAY_FILES = ("README.rst", "theory.rst")
EXPECTED_CHEATSHEETS = [
    "Arrays.rst", "Binary_Search.rst", "Bit_Manipulation.rst",
    "C++_STL.rst", "Complexity_Analysis.rst", "Dynamic_Programming.rst",
    "Graphs.rst", "Hashing.rst", "Linked_Lists.rst",
    "Recursion_Backtracking.rst", "Sorting.rst", "Stacks_Queues.rst",
    "Trees.rst",
]


def check(label: str, ok: bool, detail: str = "") -> bool:
    status = "✅ PASS" if ok else "❌ FAIL"
    msg = f"  {status}  {label}"
    if detail:
        msg += f"\n         {detail}"
    print(msg)
    return ok


def check_compiler() -> bool:
    try:
        result = subprocess.run(
            ["g++", "--version"], capture_output=True, text=True, timeout=5
        )
        if result.returncode == 0:
            version_line = result.stdout.splitlines()[0]
            return check("g++ installed", True, version_line)
        return check("g++ installed", False, "g++ returned non-zero exit code")
    except FileNotFoundError:
        return check("g++ installed", False,
                     "g++ not found. Install with: sudo apt install g++ (Linux) or Xcode CLI tools (Mac)")
    except Exception as e:
        return check("g++ installed", False, str(e))


def check_python() -> bool:
    ver = sys.version_info
    ok = ver >= (3, 8)
    return check(
        f"Python >= 3.8",
        ok,
        f"Running Python {ver.major}.{ver.minor}.{ver.micro}",
    )


def check_cpp17() -> bool:
    import tempfile, os
    test_src = '#include <bits/stdc++.h>\nint main(){auto [a,b]=std::pair{1,2};return 0;}\n'
    with tempfile.NamedTemporaryFile(suffix=".cpp", mode="w", delete=False) as f:
        f.write(test_src)
        fname = f.name
    try:
        result = subprocess.run(
            ["g++", "-std=c++17", "-o", "/dev/null", fname],
            capture_output=True, text=True, timeout=10,
        )
        os.unlink(fname)
        return check("C++17 compilation works", result.returncode == 0,
                     result.stderr.strip()[:100] if result.returncode != 0 else "")
    except Exception as e:
        return check("C++17 compilation works", False, str(e))


def check_day_folders() -> tuple[bool, list[str]]:
    issues = []
    day_dirs = sorted(
        [d for d in ROOT.iterdir() if d.is_dir() and re.match(r"Day\d+", d.name)],
        key=lambda d: int(re.match(r"Day(\d+)", d.name).group(1)),
    )
    found_days = len(day_dirs)
    if found_days != EXPECTED_DAYS:
        issues.append(f"Expected {EXPECTED_DAYS} day folders, found {found_days}")

    missing_files = []
    empty_files = []
    missing_subfolders = []
    sparse_subfolders = []

    for day_dir in day_dirs:
        for fname in REQUIRED_DAY_FILES:
            p = day_dir / fname
            if not p.exists():
                missing_files.append(str(p.relative_to(ROOT)))
            elif p.stat().st_size == 0:
                empty_files.append(str(p.relative_to(ROOT)))

        for sub in EXPECTED_SUBFOLDERS:
            sub_path = day_dir / sub
            if not sub_path.exists():
                missing_subfolders.append(str(sub_path.relative_to(ROOT)))
            else:
                cpp_files = list(sub_path.glob("*.cpp"))
                if len(cpp_files) < EXPECTED_FILES_PER_FOLDER:
                    sparse_subfolders.append(
                        f"{sub_path.relative_to(ROOT)} ({len(cpp_files)}/{EXPECTED_FILES_PER_FOLDER} files)"
                    )

    if missing_files:
        issues.append(f"Missing required files: {', '.join(missing_files[:5])}")
    if empty_files:
        issues.append(f"Empty required files: {len(empty_files)} file(s)")
    if missing_subfolders:
        issues.append(f"Missing subfolders: {', '.join(missing_subfolders[:5])}")
    if sparse_subfolders:
        issues.append(f"Sparse subfolders: {len(sparse_subfolders)} (< {EXPECTED_FILES_PER_FOLDER} cpp files)")

    ok = len(issues) == 0
    detail = " | ".join(issues) if issues else f"All {found_days} days intact"
    return check("Day folder structure", ok, detail), issues


def check_cheatsheets() -> bool:
    cheat_dir = ROOT / "cheatsheets"
    if not cheat_dir.exists():
        return check("Cheatsheets folder", False, "cheatsheets/ folder missing")
    missing = [f for f in EXPECTED_CHEATSHEETS if not (cheat_dir / f).exists()]
    empty = [f for f in EXPECTED_CHEATSHEETS
             if (cheat_dir / f).exists() and (cheat_dir / f).stat().st_size == 0]
    if missing:
        return check("Cheatsheets", False, f"Missing: {', '.join(missing)}")
    if empty:
        return check("Cheatsheets", False, f"Empty: {', '.join(empty)}")
    return check("Cheatsheets", True, f"All {len(EXPECTED_CHEATSHEETS)} cheatsheets present and non-empty")


def check_scripts() -> bool:
    script_dir = ROOT / "scripts"
    required = ["generate_readme.py", "run_tests.py", "setup.py"]
    missing = [f for f in required if not (script_dir / f).exists()]
    empty = [f for f in required
             if (script_dir / f).exists() and (script_dir / f).stat().st_size == 0]
    if missing or empty:
        detail = ""
        if missing: detail += f"Missing: {missing}. "
        if empty:   detail += f"Empty: {empty}."
        return check("Scripts", False, detail)
    return check("Scripts", True, f"All {len(required)} scripts present")


def main() -> None:
    print("=" * 55)
    print("🏥 30-Days-to-DSA-in-C++ — Repository Health Check")
    print("=" * 55)

    results = []
    results.append(check_python())
    results.append(check_compiler())
    results.append(check_cpp17())
    print()
    folder_ok, _ = check_day_folders()
    results.append(folder_ok)
    results.append(check_cheatsheets())
    results.append(check_scripts())
    print()

    passed = sum(results)
    total = len(results)
    print("=" * 55)
    if passed == total:
        print(f"✅ All {total} checks passed. Repo is healthy!")
    else:
        print(f"⚠️  {passed}/{total} checks passed. See issues above.")
    print("=" * 55)
    sys.exit(0 if passed == total else 1)


if __name__ == "__main__":
    main()
