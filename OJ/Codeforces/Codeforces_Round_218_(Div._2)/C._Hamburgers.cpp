/*
C. Hamburgers
Time Limit: 1000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/371/C
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define maxn 2000100000005;

#define debug_arr(a, n)                 \
    cerr << "[" << #a << "] = {";       \
    for (int i = 0; i < (n); i++)       \
        cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

void justdoit() {
    string hb;
    cin >> hb;
    ll ub = 0, us = 0, uc = 0;
    for (auto &e : hb) {
        if (e == 'B') ub++;
        if (e == 'S') us++;
        if (e == 'C') uc++;
    }
    ll nb, ns, nc, pb, ps, pc, m;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> m;
    ll l = 0, r = maxn;
    auto check = [&](ll c) {
        ll mm = m;
        if (c * ub > nb) {
            mm -= (c * ub - nb) * pb;
        }
        if (c * us > ns) {
            mm -= (c * us - ns) * ps;
        }
        if (c * uc > nc) {
            mm -= (c * uc - nc) * pc;
        }
        if (mm >= 0) return true;
        return false;
    };
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
        debug(l, r);
    }
    debug(l);
    cout << l - 1 << endl;
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