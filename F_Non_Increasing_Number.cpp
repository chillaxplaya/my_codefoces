#include <bits/stdc++.h>
#include <vector>
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
void solve1() {
    int x;
    cin >> x;

    int state = 10 * x;                   // 0 .. 10x-1
    vector<char> vis(state, 0);
    vector<int> pre(state, -1);

    queue<int> qu;
    vis[0] = 1;                           // 入队即标记
    qu.push(0);

    while (!qu.empty()) {
        int p = qu.front();
        qu.pop();

        int last_digit = p % 10;
        int remainder  = p / 10;

        for (int digit = max(1, last_digit); digit <= 9; digit++) {
            int next_remainder = (remainder * 10 + digit) % x;
            int next_state = next_remainder * 10 + digit;

            if (vis[next_state]) continue;
            vis[next_state] = 1;
            pre[next_state] = p;
            qu.push(next_state);

            if (next_remainder == 0) {
                vector<int> res;
                int cur = next_state;
                while (cur != 0) {
                    res.push_back(cur % 10);
                    cur = pre[cur];
                }
                reverse(res.begin(), res.end());
                for (int d : res) cout << d;
                cout << "\n";
                return;
            }
        }
    }

    cout << -1 << "\n";
}

void solve() {
    int x;
    cin >> x;
    int state = x * 10 + 1;
    vector<int> vis(state);
    vector<int> pre(state, -1);
    queue<int> qu;
    qu.push(0);
    vis[0] = 1;
    while (!qu.empty()) {
        int p = qu.front();
        // debug(p);
        qu.pop();
        
        int last_digit = p % 10;
        int remainder = p / 10;

        for (int i = max(1, last_digit); i <= 9; i++) {
            int next_remainder = (remainder * 10 + i) % x;
            int next_state = next_remainder * 10 + i;
            if (vis[next_state]) continue;
            debug(p);
            pre[next_state] = p;
            debug(next_state);
            if (vis[next_state]) continue;
            vis[next_state] = 1;
            qu.push(next_state);
            if (next_remainder == 0) {
                vector<int> res;
                int qstate = next_state;
                while (qstate != 0) {
                    res.push_back(qstate % 10);
                    qstate = pre[qstate];
                }
                reverse(all(res));
                for (auto& e : res) cout << e;
                cout << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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