/*
A - Seats 2
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc447/tasks/abc447_a
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
    int n, m;
    cin >> n >> m;
    if ((n + 1) / m >= 2) {
        cout << "Yes";
    } else {
        cout << "No";
    }
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