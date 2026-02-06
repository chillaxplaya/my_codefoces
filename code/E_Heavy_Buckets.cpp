#include <bits/stdc++.h>
#include <climits>
#include <vector>
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
#define rep(i, n) for (int i = 0; i < n; i++)
//2^30 > 1000000000
//
int lowbit(int x) {
    return x & -x;
}
map<int, int> n2;
int getn(int x) {
    if (x == 1) {
        return 0;
    }
    if (n2.count(x)) return n2[x];
    for (int i = 1; i <= 30; i++) {
        if (x == (1 << i)) {
            n2[x] = i;
            return i;
        }
    }
}
void justdoit() {
    debug(INT_MAX);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> next(n + 1, vector<int>(32));
    vector<vector<ll>> sum(n + 1, vector<ll>(32));
    for (int i = 1; i <= n; i++) {
        next[i][0] = a[i];
        sum[i][0] = i;
    }
    for (int j = 1; j <= 30; j++) {
        for (int i = 1; i <= n; i++) {
            next[i][j] = next[next[i][j - 1]][j - 1];
            sum[i][j] = sum[i][j - 1] + sum[next[i][j - 1]][j - 1];
        }
    }
    int t, b;
    for (int i = 0; i < q; i++) {
        cin >> t >> b;
        int now = b;
        ll res = 0;
        while(t > 0) {
            int cnt = lowbit(t);
            debug(t, cnt);
            t -= cnt;
            res += sum[now][getn(cnt)];
            now = next[now][getn(cnt)];
        }
        cout << res << '\n';
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