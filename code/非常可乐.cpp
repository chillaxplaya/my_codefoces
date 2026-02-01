#include <bits/stdc++.h>
#include <cstring>
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
int step[105][105];
void solve() {
    int am[3];
    while (cin >> am[0] >> am[1] >> am[2] && am[0]) {
        if (am[0] % 2) {
            cout << "NO\n";
            continue;
        }
        debug(am[0], am[1], am[2]);
        if (am[1] < am[2]) swap(am[1], am[2]);
        bool success = false;
        memset(step, 0, sizeof(step));
        step[0][0] = 1;
        queue<pair<int, int>> qu;
        qu.push({0, 0});
        int a[3];
        while (!qu.empty()) {
            // debug(am[0] - qu.front().first - qu.front().second, qu.front().first, qu.front().second);
            if (qu.front().first == am[0] / 2  && qu.front().second == 0) {
                cout << step[qu.front().first][qu.front().second] - 1 << "\n";
                success = true;
                break;
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == j) continue;
                    a[0] = am[0] - qu.front().first - qu.front().second;
                    a[1] = qu.front().first;
                    a[2] = qu.front().second;
                    if (a[i] + a[j] <= am[j]) {
                        a[j] += a[i];
                        a[i] = 0;
                    } else {
                        a[i] -= (am[j] - a[j]);
                        a[j] = am[j];
                    }
                    if (step[a[1]][a[2]] == 0) {
                        step[a[1]][a[2]] = step[qu.front().first][qu.front().second] + 1;
                        qu.push({a[1], a[2]});
                    }
                }
            }
            qu.pop();

        }
        if (!success) {
            cout << "NO\n";
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