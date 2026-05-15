/*
最大礼物数
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-07 16:12:21
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define endl '\n'
struct Cow {
    ll p, s;
    ll w, cw;
    Cow() {}
    Cow(int _p, int _s) : p(_p), s(_s) {
        w = _p + _s;
        cw = _p / 2 + _s;
    }
};
vector<Cow> a;
void justdoit() {
    int n;
    ll b ,p, s;
    cin >> n >> b;
    rep(i, n) {
        cin >> p >> s;
        a.push_back(Cow(p, s));
    }
    int res = 0;
    sort(all(a), [](const Cow &a, const Cow &b) {
        return a.w < b.w;
    });
    for (int i = 0; i < n; i++) {
        if (a[i].cw > b) continue;
        ll sum = a[i].cw;
        int cnt = 1;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (sum + a[j].w <= b) {
                sum += a[j].w;
                cnt++;
            } else {
                break;
            }
        }
        res = max(res, cnt);
    }
    cout << res << endl;
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