/*
跳跃数
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-13 16:22:22
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
typedef pair<int, int> pi;

void justdoit() {
    int k;
    cin >> k;
    queue<ll> qu;
    for (int i = 1; i < 10; i++) {
        qu.push(i);
    }
    while (!qu.empty()) {
        ll x = qu.front();
        qu.pop();
        k--;
        if (k == 0) {
            cout << x << endl;
            return;
        }
        ll first = x % 10;
        for (int i = first + 2; i <= 9; i++) {
            qu.push(x * 10 + i);
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