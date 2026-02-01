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

void solve() {
    int n, op;
    cin >> n;
    int vol = 0, p = 0;
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == 1) {
            vol++;
        } else if (op == 2) {
            vol--;
            if (vol < 0) vol = 0;
        } else {
            p = 1 - p;
        }
        if (vol >= 3 && p == 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
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