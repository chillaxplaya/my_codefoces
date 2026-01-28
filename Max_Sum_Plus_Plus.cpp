#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define mem(a,b) memset(a,b,sizeof(a))
#define debug_arr(a, n) \
    cerr << "[" << #a << "] = {"; \
    for (int i = 0; i < (n); i++) cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";


#define all(x) (x).begin(), (x).end()
#define ll long long
#define MAXN 1000005;
int a[1000005];
int dp[2005][2005];
void solve() {
    int n, m;
    while ( cin >> m && cin >> n) {
        swap(n,m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            dp[i][1] = a[i];
        }
        debug(n , m);
        cerr << dp[0][1] << " ";
        for (int i = 1; i < n; i++) {
            dp[i][1] = max(dp[i][1], dp[i - 1][1] + a[i]);
            cerr << dp[i][1] << " ";
        }
        cerr << "\n";
        for (int i = 2; i <= m; i++) {
            for (int j = i - 1; j < n; j++) {
                if (j == i - 1) {
                    dp[j][i] = a[j] + dp[j - 1][i - 1];
                } else {
                     int temp = -0x3f3f3f3f;
                     for (int k = j - 1; k >= i - 2; k--) {
                        temp = max(temp, dp[k][i - 1]);
                     }
                     dp[j][i] = max(dp[j - 1][i], temp + a[j]);
                }
                cerr << dp[j][i] << " ";
            }
            cerr << "\n";
        }
        int ans = 0;
        for (int i = m - 1; i < n; i++) {
            ans = max(ans, dp[i][m]);
        }
        cout << ans << "\n";
        break;
    }

}//https://
// 9
// 1
// po
// rn
// y.com/vi
// deo/v
// iew/5
// 9bfe7
// 74649ee0df7ea4
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}