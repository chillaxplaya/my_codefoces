/*
2b
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-02 19:45:40
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

// + 2 * n + 1
// + n + 2
// 1. -n-2,  2. -2n-1  3. -2n+1 4. -n+2
// 5. +n-2,  6. +2n-1  7. +2n+1 8. +n+2
string s, t;
int ssize, tsize;
int n;
int dir[8];
bool dfs(int idx, int k) {
    if (k == tsize) {
        debug(idx);
        return true;
    }
    rep(i, 8) {
        int nextidx = idx + dir[i];
        if (nextidx < 0 || nextidx >= ssize) continue;
        int r = idx / n;
        int c = idx % n;
        int nr = nextidx / n;
        int nc = nextidx % n;

        int dr = abs(nr - r);
        int dc = abs(nc - c);

        if (!((dr == 2 && dc == 1) || (dr == 1 && dc == 2))) continue;
        if (s[nextidx] == t[k]) {
            if (dfs(nextidx, k + 1)) { return true; }
        }
    }
    return false;
}
void justdoit() {
    cin >> n;
    
    dir[0] = -n - 2;
    dir[1] = -2 * n - 1;
    dir[2] = -2 * n + 1;
    dir[3] = -n + 2;
    dir[4] = n - 2;
    dir[5] = 2 * n - 1;
    dir[6] = 2 * n + 1;
    dir[7] = n + 2;
    cin >> s >> t;
    ssize = s.size();
    tsize = t.size();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[0]) {
            if (dfs(i, 1)) {
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
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