/*
E. Romantic Glasses
Time Limit: 1000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/1915/E
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n)                 \
    cerr << "[" << #a << "] = {";       \
    for (int i = 0; i < (n); i++)       \
        cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

void justdoit() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    map<ll, int> creep;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            cin >> a[i];
            b[i] = 0;
        } else {
            cin >> b[i];
            a[i] = 0;
        }
        a[i] += i > 0 ? a[i - 1] : 0;
        b[i] += i > 0 ? b[i - 1] : 0;
    }
    creep[0] = 1;
    for (int i = 0; i < n; i++) {
        if (creep[a[i] - b[i]] == 1) {
            cout << "YES\n";
            return;
        }
        creep[a[i] - b[i]] = 1;
    }
    cout << "NO\n";
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