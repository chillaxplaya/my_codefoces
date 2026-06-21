/*
C - Drop Blocks
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc459/tasks/abc459_c
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

void justdoit() {
    int n, q, t, v;
    cin >> n >> q;
    vector<int> blocks(n + 1, 0);
    vector<int> cnt(600005, 0);
    cnt[0] = n;
    int min_cnt = 1;
    while (q--) {
        cin >> t >> v;
        if (t == 1) {
            blocks[v - 1]++;
            cnt[blocks[v - 1]]++;
            while (cnt[min_cnt] == n) min_cnt++;
        } else {
            cout << cnt[v + min_cnt - 1] << endl;
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