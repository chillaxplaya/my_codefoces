/*
B - The Honest Woodcutters
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc461/tasks/abc461_b
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
    int n, x;
    bool flag = true;
    cin >> n;
    vector<int> have(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> have[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (have[x] != i) {
            flag = false;
        }
    }
    cout << (flag ? "Yes" : "No");
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