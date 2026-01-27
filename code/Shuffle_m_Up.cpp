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
int rd = 0;
void solve() {
    rd++;
    int n;
    string a, b, s1, s;
    cin >> n;
    cin >> a >> b >> s;
    string qus = a + b;
    unordered_set<string> vis;
    int step = 0;
    while(1) {
        step++;
        string s0 = "";
        a = qus.substr(0, n);
        b = qus.substr(n, n);
        for (int i = 0; i < n; i++) {
            s0 += b[i];
            s0 += a[i];
        }
        if (s0 == s) {
            cout << rd << " " << step << "\n";
            return;
        }
        if(vis.count(s0)) {
            cout << rd << " " << -1 << "\n";
            return;
        }
        debug(s0);
        vis.insert(s0);
        qus = s0;

    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}