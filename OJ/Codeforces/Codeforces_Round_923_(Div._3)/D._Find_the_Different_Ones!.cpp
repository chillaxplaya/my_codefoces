/*
D. Find the Different Ones!
Time Limit: 5000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/1927/D
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
    cin >> n;
    vector<int> a(n);
    vector<int> nextdif(n);
    
    rep(i, n) {
        cin >> a[i];
    }
    nextdif[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] == a[i + 1]) {
            nextdif[i] = nextdif[i + 1];
        } else {
            nextdif[i] = i + 1;
        }
    }
    cin >> m;
    int l, r;
    rep(i, m) {
        cin >> l >> r;
        if (nextdif[l - 1] < r) {
            cout << l << " " << nextdif[l - 1] + 1 << '\n';
        } else {
            cout << "-1 -1\n";
        }
    }
    cout << '\n';
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