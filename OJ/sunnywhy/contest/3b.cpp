/*
3b
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-02 20:37:58
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
int judd(ll a, ll b, ll n) {
    
}
void justdoit() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    rep(i ,m) {
        cin >> a[i];
    }
    ll res = 0;
    for (int i = 1; i < m; i++) {
        
        for (int i = n - 1; i >= 0; i--) {
            if (a[i - 1] % (1 << (n - 1)) == a[i] % (1 << (n - 1))) {
                res += (n )
            }
        }    
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