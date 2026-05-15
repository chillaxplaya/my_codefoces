/*
D. 最长合法表达式
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-11 19:37:51
user: playa
*/
#include <bits/stdc++.h>
#include <string>
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
    char c;
    int U = 0;
    int B = 0;
    vector<string> op;
    while ((c = getchar()) != EOF) {
        if (c == 'n') break;
        if (c == 'U') {
            U++;
        } else if (c == 'B') {
            B++;
        } else {
            op.push_back(string("") + c);
        }
    }

    while(U--) {
        if (op.empty()) break;
        string t = "U" + op.back();
        op.pop_back();
        op.push_back(t);
    }
    while(B--) {
        if (op.size() < 2) break;
        string t = "B" + op.back();
        op.pop_back();
        t += op.back();
        op.pop_back();
        op.push_back(t);
    }
    if (op.size() > 0) {
        cout << op.back();
    } else {
        cout << "no valid expression";
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