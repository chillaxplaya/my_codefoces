/*
C. Omsk Programmers
Time Limit: 1000ms Memory Limit: 256MB
URL: https://codeforces.com/contest/2236/problem/C
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
    int a, b, x;
    cin >> a >> b >> x;
    int div = 0;
    int ans = abs(b - a);
    while (a || b) {
        if (a > b) a /= x;
        else b /= x;
        div += 1;
        ans = min(ans, abs(a - b) + div);
    }
    // ans = min(ans, abs(a - b) + div);
    cout << ans << endl;
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