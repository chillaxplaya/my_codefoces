/*
K个切割点
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-08 15:02:47
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

void justdoit() {
    int n, k, L;
    cin >> n >> k >> L;
    vector<int> a(n);
    for (auto &e : a) {
        cin >> e;
    }
    int l = 1, r = L;
    sort(all(a));
    while (l < r) {
        int mid = l + (r - l) / 2;
        bool ok = true;
        int pre = 0;
        int prei = -1;
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            if (!ok) break;
            
            for (int j = prei + 1; j < n; j++) {
                if (pre + mid <= a[j]) {
                    if (mid == 4) {
                        debug(a[j], cnt++);
                    }
                    pre = a[j];
                    prei = j;
                   
                    break;
                }
                if (j == n - 1) {
                    ok = false;
                } 
            }
        }
        if (L - pre < mid) ok = false;
        debug(mid, ok);
        if (ok) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << l - 1;
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