/*
回文字符串
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-02 16:42:18
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
string s;
bool is_p(int l, int r) {
    if (l > r) {
        return true;
    }
    return s[l] == s[r] && is_p(l + 1, r - 1);
}
void justdoit() {
    cin >> s;
    cout << (is_p(0, s.length() - 1) ? "Yes" : "No");
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