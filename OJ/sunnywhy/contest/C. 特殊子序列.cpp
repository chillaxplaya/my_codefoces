/*
C. 特殊子序列
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-14 20:11:22
user: playa
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
#define mod 1000000007
typedef pair<int, int> pi;

void justdoit() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> aidx;
    vector<int> cidx;
    ll res = 0;
    vector<ll> modres(10005);
    modres[0] = 0;
    modres[1] = 1;
    
    cout << res;
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