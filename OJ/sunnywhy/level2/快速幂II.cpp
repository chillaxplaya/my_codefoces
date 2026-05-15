/*
装水问题
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-03 09:03:32
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
ll qpow(ll a, ll b, ll c) {
    ll ans = 1;
    while (b > 0) {
        if (b % 2) {
            ans *= a;
            ans %= c;
        }
        a = ((a * a) % c);
        b /= 2;
    }
    return  ans;
}
void justdoit() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << qpow(a, b, c);
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