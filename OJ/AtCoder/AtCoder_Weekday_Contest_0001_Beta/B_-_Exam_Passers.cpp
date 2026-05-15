/*
B - Exam Passers
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/awc0001/tasks/awc0001_b
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
    int n, l, r, x;
    cin >> n >> l >> r;
    int maxscore = -1;
    int maxidx = -1;
    rep(i, n) {
        cin >> x;
        if (x >= l && x <= r && x > maxscore) {
            maxscore = x;
            maxidx = i + 1;
        }   
    }
    cout << maxidx << endl;
}
int main() {
    // srand(time(0));
    // ios::sync_with_stdio(0);
    // cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        justdoit();
    return 0;
}