/*
C. 装饰珠串
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-10 19:43:10
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
int n;
string s;
int snum;
int use[20][1 << 14];
int wi[20];
int lens[] = {0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047,4085, 8191, 16383};
int ans = 0x3f3f3f3f;
int dfs(int k, int sum_wi, int nows) {
    if (k == n) {
        ans = min(ans, sum_wi);
        return 0;
    }
    for (int i = 1; i <= (n - k); i++) {
        int nextstate = nows & lens[i];
        debug(nextstate);
        debug(sum_wi);
        if (use[i][nextstate]) {
            dfs(k + i, sum_wi, nows >> i);
        } else {
            use[i][nextstate] = 1;
            dfs(k + i, sum_wi + wi[i], nows >> i);
            use[i][nextstate] = 0;
        }
    }
    return 0;
}
void justdoit() {

    cin >> s;
    n = s.size();
    snum = 0;
    for (auto &e : s) {
        snum *= 2;
        if (e == 'R') {
            snum += 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> wi[i];
    }
    debug(snum);
    dfs(0, 0, snum);
    cout << ans;
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