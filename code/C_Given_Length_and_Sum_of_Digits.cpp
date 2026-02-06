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
#define rep(i,n) for (int i = 0; i < n; i++)

void solve() {
    int m, s;
    cin >> m >> s;
    if (m == 1 && s == 0) {
        cout <<"0 0\n";
        return ;
    }
    if (m * 9 < s || s == 0 || m == 0) {
        cout <<"-1 -1\n";
        return ;
    }
    string num(m, '0');
    int t = s;
    int idx = m - 1;
    while (t > 0) {
        if (t >= 9) {
            num[idx] =  '9';
            t -= 9;
        } else if (t > 0) {
            num[idx] = '0' + t;
            t = 0;
        }
        debug(num, t, num[0]);
        if (t == 0 && num[0] == '0') {
            num[idx]--;
            num[0] = '1';
        }
        debug(num);
        idx--;
    }
    cout << num << ' ';
    num = string(m, '0');
    idx = 0;
    t = s;
    while (t > 0) {
        if (t >= 9) {
            num[idx] =  '9';
            t -= 9;
        } else if (t > 0) {
            num[idx] = '0' + t;
            t = 0;
        }
        idx++;
    }
    cout << num << '\n';
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