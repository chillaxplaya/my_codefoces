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
    int n, x;
    cin >> n;
    int count0 = 0, count1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) { count0++; }
        if (x == 0) { count1++; }
    }
    if (count0 == 0) {
        cout << "NO" << "\n";
    } else if (count0 == 1) {
        cout << "YES" << "\n";
    } else if (count0 > 1 && count1 == 0) {
        cout << "NO" << "\n";
    } else if (count0 > 1 && count1 > 0) {
        cout << "YES" << "\n";
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