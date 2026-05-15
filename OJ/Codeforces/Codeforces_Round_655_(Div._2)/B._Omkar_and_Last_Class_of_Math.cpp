/*
B. Omkar and Last Class of Math
Time Limit: 1000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/1372/B
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
    if (n % 2 == 0) {
        cout << (n/2) << " " << (n/2) << '\n';
        return;
    }
    int sq = sqrt(n);
    for (int i = 3; i <= sq; i++) {
        if (n % i == 0) {
            cout << n / i << " " << n - n / i << "\n";
            return;
        }
    }
    cout << 1 << " " << n - 1 << '\n';
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