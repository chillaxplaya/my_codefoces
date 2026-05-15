/*
B. Array and Permutation
Time Limit: 1500ms Memory Limit: 256MB
URL: https://codeforces.com/contest/2197/problem/B
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
    int n;
    
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int pre = -1;
    int idx = 0;
    int x;
    bool ok = true;
    rep(i, n) {
        cin >> x;
        debug(x);
        if (x == pre) continue;
        int j;
        for (j = idx; j < n; j++) {
            if (a[j] == x) {
                break;
            }
        }
        idx = j;
        if (idx == n) {
            ok = false;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
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