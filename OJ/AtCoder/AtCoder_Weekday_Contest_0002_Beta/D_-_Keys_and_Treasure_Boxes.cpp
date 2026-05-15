/*
D - Keys and Treasure Boxes
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/awc0002/tasks/awc0002_d
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

void justdoit() {
    int n, m;
    cin >> n >> m;
    vector<int> box(n);
    vector<int> key(m);
    rep(i,n) {
        cin >> box[i];
    }
    sort(all(box));
    rep(i, m) {
        cin >> key[i];
    }
    sort(all(key));
    debug(key);
    debug(box);
    int i = 0, j = 0;
    int res = 0;
    while (i < n && j < m) {
        if (key[j] >= box[i]) {
            res++;
            i++;
            j++;
        } else {
            j++;
        }
    }
    cout << res;
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