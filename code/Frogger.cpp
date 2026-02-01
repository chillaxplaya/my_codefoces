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
typedef pair<int, int> pi;
#define INF 0x3f3f3f3f
int dis[205];
int vis[205];
int co_x[205], co_y[205];
int caldis2(int i, int j) {
    int a = abs(co_x[i] - co_x[j]);
    int b = abs(co_y[i] - co_y[j]);
    return (a * a + b * b);
}
int rd = 1;
void solve() {
    int n;
    
    while (scanf("%d", &n) && n) {
        priority_queue<pi, vector<pi>, greater<pi>> qu;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &co_x[i], &co_y[i]);
            dis[i] = INF;
            vis[i] = 0;
        }
        qu.push({0, 0});
        dis[0] = 0;
        while (!qu.empty()) {
            auto p = qu.top();
            int choosed_node = p.second;
            double cost = p.first;
            qu.pop();
            if (vis[choosed_node]) continue;
            vis[choosed_node] = 1;
            for (int i = 0; i < n; i++) {
                int jmax = max(dis[choosed_node], caldis2(choosed_node, i));
                if (!vis[i] && dis[i] > jmax) {
                    dis[i] = jmax;
                    qu.push({jmax, i});
                }
            }
        }
        
        printf("Scenario #%d\n",rd++);
        printf("Frog Distance = %.3lf\n\n", sqrt(dis[1]));
    }    
}
int main() {
    // srand(time(0));
    // ios::sync_with_stdio(0);
    // cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}