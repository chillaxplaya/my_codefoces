/*
C. Exams
Time Limit: 1000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/479/C
*/
#include <bits/stdc++.h>
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
#define INF 0x3f3f3f3f

#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
typedef pair<int, int> pi;
void justdoit() {
    int n;
    cin >> n;
    vector<pi> c(n);
    for (auto &[a, b] : c) {
        cin >> a >> b;
    }
    debug(c);
    sort(all(c));
    int nd = 0;
    for (auto &[a, b] : c) {
        nd = min((a >= nd ? a : INF), b >= nd ? b : INF);
    }
    cout << nd;
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