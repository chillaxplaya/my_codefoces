/*
A. 分组求和检查
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-15 13:31:16
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
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;
    int sum = 0;
    for (int i = 0 ; i < n; i++) {
        sum += a[i];
        if (sum == w) {
            sum = 0;
            h--;
            if (h == 0) {
                cout << "Yes";
                return;
            }
        }
        if (sum > w) {
            cout << "No";
            return;
        }
    }
    cout << "No";
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