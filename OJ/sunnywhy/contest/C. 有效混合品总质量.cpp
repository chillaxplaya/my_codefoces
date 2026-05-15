/*
C. 有效混合品总质量
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-09 20:07:00
*/
#include <bits/stdc++.h>
#include <algorithm>
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
int vis[45];
vector<ll> a;
int n;
ll sumall = 0;
ll ans = 0;
void justdoit() {

    cin >> n;
    a.resize(n);
    for (auto &e : a) {
        cin >> e;
    }
    int mid = a.size() / 2;
    
    vector<int> b(a.begin() + mid, a.end());
    a.resize(n / 2);
    int asize = a.size();
    int bsize = b.size();
    int amask = 1 << asize;
    int bmask = 1 << bsize;
    vector<ll> ares;
    for (int mask = 1; mask < amask; mask++) {
        ll sumcnt = 0;
        for (int i = 0; i < asize; i++) {
            if (mask & (1 << i)) {
                sumcnt += a[i];
            }
        }
        if (sumcnt >= 100) ans += sumcnt;
        ares.push_back(sumcnt);
    }
    sort(all(ares));
    vector<ll> preares = ares;
    for (int i = preares.size() - 2; i >= 0; i--) {
        preares[i] += preares[i + 1];
    }
    debug(preares);
    debug(ares);
    for (int mask = 1; mask < bmask; mask++) {
        ll sumcnt = 0;
        for (int i = 0; i < bsize; i++) {
            if (mask & (1 << i)) {
                sumcnt += b[i];
            }
        }
        debug(sumcnt);
        if (sumcnt >= 100) ans += sumcnt;
        auto it = (lower_bound(all(ares), 100 - sumcnt));
        if (it != ares.end())
            ans += (preares[it - ares.begin()] + (ares.end() - it) * sumcnt);
    }
    cout << ans;
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