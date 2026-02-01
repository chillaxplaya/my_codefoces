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
    string s;
    cin >> n;
    cin >> s;
    vector<int> counter(2 * n + 1);
    int d = n;
    counter[d] = 1;
    ll sum = 0;
    int ans = 0;
    for (auto& e : s) {
        if (e == 'A') {
            sum += counter[d++];
        }
        if (e == 'B') {
            sum -= counter[--d];
        }
        counter[d]++;
        ans += sum;
    }
    cout << ans << '\n';
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