# Copilot Instructions for Codeforces Competitive Programming Repository

## Project Overview
This repository contains C++ solutions for competitive programming problems from platforms like Codeforces, UVa, PTA, and others. Each `.cpp` file typically solves a single problem with standard input/output.

## Coding Conventions
- **Includes**: Use `#include <bits/stdc++.h>` for convenience in competitive coding.
- **Namespace**: `using namespace std;` is standard.
- **Macros**:
  - `all(x)`: `(x).begin(), (x).end()`
  - `ll`: `long long`
- **Debugging**: Conditional debug with `#ifdef LOCAL` including `"algo/debug.h"`, else `#define debug(...) 42`. Use `debug(variable)` for local testing.
- **I/O**: Fast I/O with `ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);`
- **Main Structure**: `int main() { ... int T=1; cin>>T; while(T--) solve(); return 0; }` with `void solve()` for test cases.

## Build and Run
- **Build**: Use VS Code task "build c++" which compiles with `g++ -g -std=gnu++17 -O2 -Wall -fexec-charset=GBK -finput-charset=UTF-8 -DLOCAL -I C:\Users\admin\codeforces`
- **Run**: Execute the generated `.exe` file, typically reading from stdin and writing to stdout.
- **Local Testing**: Define `LOCAL` during build to enable debug output.

## File Organization
- Root: Individual problem files named by problem number/title (e.g., `136_Ugly_Numbers.cpp`).
- `code/`: Main directory for solutions.
- `algo/`: Utility headers like `debug.h` for debugging.
- `pta/`: PTA-specific problems.

## Common Patterns
- **Data Structures**: Frequent use of `vector`, `queue`, `stack`, `map`, `set` from STL.
- **Algorithms**: Graph algorithms (Dijkstra, BFS), dynamic programming, string processing.
- **Input Handling**: Read integers/strings directly with `cin`, handle multiple test cases.
- **Edge Cases**: Always consider constraints; use `long long` for large numbers.

Reference: [Til_the_Cows_Come_Home.cpp](Til_the_Cows_Come_Home.cpp) for typical structure.