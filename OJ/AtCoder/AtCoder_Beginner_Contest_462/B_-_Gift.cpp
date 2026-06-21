/*
B - Gift
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc462/tasks/abc462_b
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
    int n;
    cin >> n;
    vector<vector<int>> rec(n);
    for (int i = 1; i <= n; i++) {
        int k, x;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> x;
            rec[x - 1].push_back(i);
        }
    }
    for (auto &vec : rec) {
        cout << vec.size();
        for (int i = 0 ; i < vec.size(); i++) {
            cout << ' ';
            cout << vec[i];
        }
        cout << endl;
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