#include <bits/stdc++.h>

#include <cstdio>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n)                 \
    cerr << "[" << #a << "] = {";       \
    for (int i = 0; i < (n); i++)       \
        cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
    char c;
    stack<char> pre;
    stack<char> host;
    while ((c = getchar()) != EOF) {
        if (c == '[') {
            while (!pre.empty()) {
                host.push(pre.top());
                pre.pop();
            }
        } else if (c == ']') {
            while (!host.empty()) {
                pre.push(host.top());
                host.pop();
            }
        } else if (c == '\n') {
            while (!pre.empty()) {
                host.push(pre.top());
                pre.pop();
            }
            while (!host.empty()) {
                putchar(host.top());
                host.pop();
            }
            putchar('\n');
        } else {
            pre.push(c);
        }
    }
    while (!pre.empty()) {
        host.push(pre.top());
        pre.pop();
    }
    while (!host.empty()) {
        putchar(host.top());
        host.pop();
    }
    putchar('\n');
}
void solve1() {
    list<char> words;
    int a;
    auto it = words.begin();
    while ((a = getchar()) != EOF) {
        char c = (char)a;
        if (c == '[') {
            it = words.begin();
        } else if (c == ']') {
            if (words.size() > 0)
                it = words.end();
            else
                it = words.begin();
        } else if (c == '\n') {
            for (auto e : words) {
                putchar(e);
            }
            words.clear();
            it = words.begin();
            putchar('\n');
            continue;
        } else {
            it = words.insert(it, c);
            it++;
        }
        debug(words, *it);
    }
    if (!words.empty()) {
        for (auto e : words)
            putchar(e);
        putchar('\n');
    }
}
int main() {
    // srand(time(0));
    // ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve1();
    return 0;
}