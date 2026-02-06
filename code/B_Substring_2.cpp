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

#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

void justdoit() {
    int as, bs;
    string a, b;
    cin >> as >> bs;
    cin >> a >> b;
    int ans = 0x3f3f3f3f;
    int minus = as - bs;
    debug(minus);
    for (int i = 0; i <= minus; i++) {
        int res = 0;
        for (int j = 0; j < b.size(); j++) {
            res += ((a[j + i] + 10 - b[j]) % 10);
        }
        ans = min(res, ans);
    }
    cout << ans << endl;
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