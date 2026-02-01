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
    int n;
    while (cin >> n) {
        int x;
        int cnt = 0;
        int num = -1e9;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x == num) {
                cnt++;
            } else if(cnt > 0) {
                cnt--;
            } else {
                cnt = 1;
                num = x;
            }
        }
        cout << num << '\n';
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