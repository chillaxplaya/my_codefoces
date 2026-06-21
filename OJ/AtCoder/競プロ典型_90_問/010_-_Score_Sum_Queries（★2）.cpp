/*
010 - Score Sum Queries（★2）
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/typical90/tasks/typical90_j
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
    vector<int> a(n + 1, 0);
    vector<int> b(n + 1, 0);
    int flag = 1;
    for (int i = 1; i <= n; i++) {
        cin >> flag;
        if (flag == 1) {
            cin >> a[i];
        } else {
            cin >> b[i];
        }
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }
    int q, l, r;
    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << a[r] - a[l - 1];
        cout << ' ';
        cout << b[r] - b[l - 1];
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