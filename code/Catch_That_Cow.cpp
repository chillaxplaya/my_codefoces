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
unordered_map<int, int> vis;
struct node{
    int n;
    int step;
    node(int nn, int s) : n(nn), step(s) {}
    node operator=(const node &a) {
        n = a.n;
        step = a.step;
        return a;
    }
};
void solve() {
    int n, k;
    unordered_map<int, int> vis;
    queue<node> qu;
    cin >> n >> k;
    
    qu.push(node(n, 0));
    while (!qu.empty()) {
        node now = qu.front();
        qu.pop();
        if (now.n == k) {
            cout << now.step << "\n";
            return;
        }

        if (now.n < k) {
            if (!vis.count(now.n * 2)) {
                node nxt = node(now.n * 2, now.step + 1);
                qu.push(nxt);
                vis[now.n * 2] = 1;
            }
        }
        if (!vis.count(now.n - 1)) {
            node nxt = node(now.n - 1, now.step + 1);
            qu.push(nxt);
            vis[now.n - 1] = 1;
        }
        if (!vis.count(now.n + 1)) {
            node nxt = node(now.n + 1, now.step + 1);
            qu.push(nxt);
            vis[now.n + 1] = 1;
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