/*
B. k块循环
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-04 19:35:03
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
string leftmove(string a) {
    string temp = a.substr(1, a.size() - 1);
    return temp + a[0];
}
void justdoit() {
    string s;
    cin >> s;
    int n = s.size();
    for (int k = 1; k <= n; k++) {
        if (n % k) continue;
        bool ok = true;
        for (int i = k; i < n; i += k) {
            if (leftmove(s.substr(i - k, k)) != s.substr(i, k)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << k;
            return;
        }
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