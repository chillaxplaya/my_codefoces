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
int T = 1;
void solve() {
    int n;
    
    while(cin >> n && n) {
        cout << "Scenario #" << T++ << "\n";
        queue<int> qu[n];
        queue<int> allqu;
        unordered_map<int, int> team;
        vector<int> isteam(n);
        for (int i = 0; i < n; i++) {
            int m, x;
            cin >> m;
            for (int j = 0; j < m; j++) {
                cin >> x;
                team[x] = i;
            }
        }
        debug(team);
        string cmd;
        int x;
        while (cin >> cmd && cmd != "STOP") {
            debug(cmd);
            if (cmd == "ENQUEUE") {
                cin >> x;
                if (!isteam[team[x]]) {
                    isteam[team[x]] = 1;
                    allqu.push(team[x]);   
                }
                qu[team[x]].push(x);
            } else {
                cout << qu[allqu.front()].front() << endl;
                qu[allqu.front()].pop();
                if (qu[allqu.front()].empty()) {
                    isteam[allqu.front()] = 0;
                    allqu.pop();
                }
            }
        }
        cout << "\n";
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