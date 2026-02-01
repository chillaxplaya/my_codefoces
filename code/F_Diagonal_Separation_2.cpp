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
#define MAXN 5005
char Map[MAXN][MAXN];
int pre[MAXN],suf[MAXN]; // 前缀黑色的 和后缀白 ‘.’: 白色 ‘#’: 黑色
int dp[MAXN];
int upmin[MAXN];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%s", Map[i] + 1);
        upmin[i] = 0;
    }
    upmin[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[0] = 0;
        for (int j = 1; j <= n; j++) {
            pre[j] = (Map[i][j] == '#') ? pre[j - 1] + 1 : pre[j - 1];
        }
        suf[n + 1] = 0;
        for (int j = n; j > 0; j--) {
            suf[j] = (Map[i][j] == '.') ? suf[j + 1] + 1 : suf[j + 1];
        }
        upmin[n + 1] = 0x3f3f3f3f;
        for (int j = n; j >= 0; j--) {
            dp[j] = pre[j] + suf[j + 1] +upmin[j];
            upmin[j] = min(dp[j], upmin[j + 1]);
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, dp[i]);
    }
    // cout << ans << " \n";
    printf("%d\n", ans);
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