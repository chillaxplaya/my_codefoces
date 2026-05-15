/*
绳子折叠
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-06 18:04:49
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

void justdoit() {
    int n, l, x;
    cin >> n >> l;
    vector<int> node(l + 1);
    rep(i, n) {
        cin >> x;
        node[x] = 1;
    }
    node[0] = node[l] = 1;
    int res = 0;
    for (int i = 1; i < l; i++) {
        int mid = i;
        int j = 1;
        bool ok = true;
        while(mid - j >=0 && mid + j <= l) {
            if (node[mid - j] != node[mid + j]) {
                ok = false;
            }
            j++;
        }
        if (ok) res++;
    }
    for (int i = 0; i < l; i++) {
        int k = i, j = i + 1;
        bool ok = true;
        
        while(k >=0 &&  j <= l) {
            debug(k, j);
            if (node[k--] != node[j++]) {
                ok = false;
            }
        }
        if (ok) res++;
    }
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