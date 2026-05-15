/*
B. 仓库调货
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-09 19:38:08
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
    int n, q, d, pos, need;
    // cin >> n >> q >> d;
    scanf("%d %d %d", &n, &q, &d);
    vector<pair<int, int>> store(n);
    ll sum = 0;
    for (auto &[x, y] : store) {
        // cin >> x >> y;
        scanf("%d %d", &x, &y);
        sum += y;
    }
    sort(all(store));
    vector<ll> prestore(n);
    prestore[0] = store[0].second;
    for (int i = 1; i < n; i++) {
        prestore[i] = store[i].second;
        prestore[i] += prestore[i - 1];
    }
    debug(prestore);
    rep(i, q) {
        // cin >> pos >> need;
        scanf("%d %d", &pos, &need);
        
        if (need > sum) {
            cout << "no" << endl;
            continue;
        }
        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (store[mid].first > pos + d) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        while(l > 0 && l < n && store[l].first > pos + d) l--;
        int end = l;
        l = 0;
        r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (store[mid].first >= pos - d) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int start = l;
        if (end == n) end--;
        if (start > end) {
            cout << "no" << endl;
            continue;
        }
        if (start > 0) 
            need -= (prestore[end] - prestore[start - 1]);
        else 
            need -= prestore[end];
        debug(need);
        if (need > 0) {
            cout << "no" << endl;
        } else {
            cout << "yes" << endl;
        }
    }
}
int main() {
    // // srand(time(0));
    // ios::sync_with_stdio(0);
    // cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        justdoit();
    return 0;
}