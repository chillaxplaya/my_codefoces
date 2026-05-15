/*
C. Number of Ways
Time Limit: 2000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/466/C
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n)                 \
    cerr << "[" << #a << "] = {";       \
    for (int i = 0; i < (n); i++)       \
        cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
/*
6
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000

*/
void justdoit() {
    int n;
    cin >> n;
    ll sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 3) {
        cout << 0;
        return;
    }
    vector<int> suf(n);
    ll suf_sum = 0;
    int cnt_sum = 0;
    for (int i = n - 1; i > 0; i--) {
        suf_sum += a[i];
        if (suf_sum == sum / 3) {
            ++cnt_sum;
        }
        suf[i] = cnt_sum;
    }
    ll ans = 0;
    ll pre_sum = 0;
    for (int i = 0; i < n - 2; i++) {
        pre_sum += a[i];
        if (pre_sum == sum / 3) {
            ans += (ll)suf[i + 2];
        }
    }
    cout << ans << "\n";
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        justdoit();
    return 0;
}