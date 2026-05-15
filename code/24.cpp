/*
24
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-16 22:51:24
user: playa
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
typedef pair<int, int> pi;
#define eps 1E-12
double a[4];
void dfs(int k, double sum, string op) {
    if (k == 4) {
        if (!(abs(sum - 24.0) > eps)) {
            cout << (int)a[0];
            rep(i, 3) {
                cout << " " << op[i + 1] << " " << (int)a[i + 1];
            }
            cout << endl;
        }
        return;
    }
    dfs(k + 1, sum + a[k], op + "+");
    if (k != 0) {
        dfs(k + 1, sum - a[k], op + "-");
        dfs(k + 1, sum * a[k], op + "*");
        dfs(k + 1, sum / a[k], op + "/");
    }
}
void justdoit() {
    rep(i, 4) cin >> a[i];
    dfs(0, 0, "");
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