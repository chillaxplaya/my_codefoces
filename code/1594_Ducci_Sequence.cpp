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

void solve() {
    int n;
    cin >> n;
    set<vector<int>> looop;
    vector<int> zero(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (true) {
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = abs(a[i] - a[(i + 1) % n]);
        }
        debug(b);
        if (looop.count(b)) {
            cout << "LOOP" << "\n";
            return;
        } else if(b == zero) {
            cout << "ZERO\n";
            return;
        }
        looop.insert(b);
        a = b;
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