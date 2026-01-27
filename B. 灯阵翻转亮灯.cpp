#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n) \
    cerr << "[" << #a << "] = {"; \
    for (int i = 0; i < (n); i++) cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";


#define all(x) (x).begin(), (x).end()
#define ll long long
string Map[105];
int rowcnt[105];
int colcnt[105];
void solve() {
    char c;
    int n = 0, m = 0;
    int cnt = 0;
    while (getline(cin, Map[n])) {
        for (int i = 0; i < Map[n].size(); i++) {
            if (Map[n][i] == '1') {
                rowcnt[n]++;
                colcnt[i]++;
                cnt++;
            }
        }
        n++;
    }
    int ans = 0;
    m = Map[0].size();
    debug(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c1, c0;
            c1 = rowcnt[i] + colcnt[j] - 2 * (Map[i][j] - '0');
            c0 = n + m - 2 - c1;
            ans = max(ans, cnt - c1 + c0);
        }
    }
    cout << ans << "\n";
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}