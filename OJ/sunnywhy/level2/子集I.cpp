/*
子集I
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-03 16:10:11
*/
#include <bits/stdc++.h>
#include <vector>
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
int b[1005];
void dfs(vector<int> &a, int pre, int k, int l, int n) {
    if (k >= l) {
        for (int i = 0; i < l; i++) {
            if (i) cout << " ";
            cout << a[i];
        }
        cout << endl;

        return;
    }
    
    for (int i = pre + 1; i < n; i++) {
        a[k] = b[i];
        dfs(a, i, k + 1, l, n);
    }
    return;
}
void justdoit() {
    int n;
    cin >> n;
    cout << endl;
    rep(i, n) {
        cin >> b[i];
    }
    vector<int> a(n);
    for (int i = 1; i <= n; i++) {
        dfs(a, -1, 0, i, n);
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