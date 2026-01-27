#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n)                                           \
    cerr << "[" << #a << "] = {";                                 \
    for (int i = 0; i < (n); i++) cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

#define all(x) (x).begin(), (x).end()
#define ll long long
bool ismod(string s, ll x) {
    ll res = 0;
    for (auto e : s) { res = (res * 10 + (e - '0')) % x; }
    return res == 0;
}
void solve() {
    int n;
    while (cin >> n && n) {
        queue<string> qu;
        qu.push("1");
        while (!qu.empty()) {
            if (ismod(qu.front(), (ll)n)) {
                cout << qu.front() << "\n";
                break;
            }
            qu.push(qu.front() + "0");
            qu.push(qu.front() + "1");
            qu.pop();
        }
    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}