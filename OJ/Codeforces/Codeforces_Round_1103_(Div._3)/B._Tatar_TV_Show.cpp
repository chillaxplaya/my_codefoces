/*
B. Tatar TV Show
Time Limit: 2000ms Memory Limit: 256MB
URL: https://codeforces.com/contest/2236/problem/B
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n - k; i++) {
        if (s[i] == '1') {
            s[i + k] = s[i + k] == '0' ? '1' : '0';
        }
    }
    for (int i = n - k; i < n; i++) {
        if (s[i] == '1') {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        justdoit();
    return 0;
}