/*
B. 简单文本编辑器
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-10 19:35:15
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define endl '\n'

void justdoit() {
    stack<char> left;
    stack<char> right;
    char c;
    while((c = getchar()) != EOF) {
        if (c == '<') {
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        } else if (c == '>') {
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        } else if (c == '-') {
            if (!left.empty()) {
                left.pop();
            }
        } else {
            left.push(c);
        }
    }
    vector<char> res;
    while (!left.empty()) {
        res.push_back(left.top());
        left.pop();
    }
    reverse(all(res));
    while (!right.empty()) {
        res.push_back(right.top());
        right.pop();
    }
    for (auto &e : res) {
        cout << e;
    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        justdoit();
    return 0;
}