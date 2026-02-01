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
int count1(string &s) {
    int ret = 0;
    for (auto &e : s) {
        if (e == '1') ret++;
    }
    return ret;
}
void solve() {
    int n;
    string s;
    cin >> n; 
    cin >> s;
    int ans = 0;
    ans += count1(s);
    s = "10" + s + "01";
    int l = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '1') {
            ans += ((i - l) - 1) / 3;
            l = i;
        }
    }
    cout << ans << "\n";
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