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
#define rep(i,n) for (int i = 0; i < n; i++)
int dis[10005];
void solve() {
    int n, m;
    cin >> n >> m;
    dis[n] = 1;
    queue<int> qu;
    qu.push(n);
    while (!qu.empty()) {
        int now_state = qu.front();
        qu.pop();
        if(now_state == m) {
            cout << dis[m] - 1 << "\n";
            return;
        }
        if (now_state - 1 >= 0 && !dis[now_state - 1]) {
            dis[now_state - 1] = dis[now_state] + 1;
            qu.push(now_state - 1);
        }
        if (now_state * 2 <= 10000 && !dis[now_state * 2]) {
            dis[now_state * 2] = dis[now_state] + 1;
            qu.push(now_state * 2);
        }
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