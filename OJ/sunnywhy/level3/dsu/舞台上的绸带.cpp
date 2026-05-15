/*
舞台上的绸带
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-16 15:22:21
user: playa
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
typedef pair<int, int> pi;

vector<int> pa;
int findp(int x) {
    return x == pa[x] ? x : pa[x] = findp(pa[x]);
}
void dsuunion(int x, int y) {
    int pax = findp(x);
    int pay = findp(y);
    if (pax < pay) {
        pa[pay] = pax;
    } else {
        pa[pax] = pay;
    }
}
void justdoit() {
    int n, k;
    cin >> n >> k;
    pa.resize(1005, -1);
    vector<int> a(n);
    for (auto &e : a) {
        cin >> e;
        pa[e] = e;
    }
    sort(all(a));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] - a[i] <= k) {
                dsuunion(a[j], a[i]);
            }
        }
    }
    int cnt = 0;
    for (int i = 1;i <= 1000; i++) {
        if (i == pa[i]) cnt++;
    }
    cout << cnt - 1;
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