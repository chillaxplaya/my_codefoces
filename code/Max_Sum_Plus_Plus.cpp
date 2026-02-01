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
#define MAXN 1000005
int m, n;
int a[MAXN], dp[MAXN],pre[MAXN];
void solve() {
    while (cin >> m >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            
        }
        memset(dp, 0, sizeof(dp));
        memset(pre, 0 ,sizeof(pre));
        int temp;
        for (int i = 1; i <= m; i++) {
            temp = -1e9;
            for (int j = i; j <= n; j++) {
                dp[j] = max(dp[j - 1], pre[j - 1]) + a[j];
                pre[j - 1] = temp;
                temp = max(temp, dp[j]);
            }
        }
        cout << temp << "\n";
    }
    
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