/*
A. 序列重复查找
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-13 19:31:50
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
int a[30005];
int vis[10005];
void justdoit() {
    int m;
    cin >> m;
    a[0] = a[1] = 1;
    for (int i = 2;; i++) {
        a[i] = (a[i - 1] + a[i - 2] + 1) % m;
        if (vis[a[i]]) {
            cout << i << endl;
            break;
        }
        vis[a[i]] = 1;
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