/*
C - Reindeer and Sleigh 2
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc437/tasks/abc437_c
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

void justdoit() {
    ll n, wi, si, w = 0;
    cin >> n;
    vector<ll> item;
    int pre_ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> wi >> si;
        if (wi > si) {
            item.push_back(wi - si);
        } else {
            pre_ans++;
            w += (si - wi);
        }
    }
    debug(w, pre_ans);
    debug(item);
    sort(all(item));
    for (auto &i : item) {
        if (i <= w) {
            w -= i;
            pre_ans++;
        } else {
            break;
        }
    }
    cout << pre_ans << endl;
    return;
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        justdoit();
    return 0;
}