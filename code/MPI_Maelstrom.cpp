#include <bits/stdc++.h>
#include <cstdio>
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

int read() {
    char c;
    while((c = getchar())) {
        if (c != ' ' && c != '\n') break;
    }
    if (c == 'x') return -1;
    int sum = 0;
    sum += c - '0';
    while((c = getchar())) {
        if (c == ' ' || c == '\n') break;
        sum = sum * 10 + (c - '0');
    }
    return sum;
}
#define all(x) (x).begin(), (x).end()
#define ll long long
typedef pair<int, int> pi;
int vis[105];
int dis[105];
void solve() {
    int n = read(), x;
    vector<vector<pi>> g(n);
    debug(n);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            x = read();
            if (x != -1) {
                g[i].push_back({j, x});
                g[j].push_back({i, x});
            }
        }
    }
    priority_queue<pi, vector<pi>, greater<pi>> qu;
    qu.push({0 ,0});
    memset(dis, 0x3f, sizeof(dis));
    dis[0] = 0;
    int ans = 0;
    while (!qu.empty()) {
        auto p = qu.top();
        qu.pop();
        if (vis[p.second]) continue;
        int choosed_node = p.second;
        int choosed_dis = p.first;
        if (choosed_dis > ans) {
            ans = choosed_dis;
        }
        vis[choosed_node] = 1;
        for (auto e : g[choosed_node]) {
            if (dis[e.first] > dis[choosed_node] + e.second) {
                dis[e.first] = dis[choosed_node] + e.second;
                qu.push({dis[e.first], e.first});
            }
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