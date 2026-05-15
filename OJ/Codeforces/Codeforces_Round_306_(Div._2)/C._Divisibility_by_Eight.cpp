/*
C. Divisibility by Eight
Time Limit: 2000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/550/C
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
bool is_substr(string s, string x) {
    int idx = x.size();
    int i = 0;
    for (auto &e : s) {
        if (e == x[i]) {
            i++;
            if (i == idx) {
                return true;
            }
        }
    }

    return false;
}
void justdoit() {
    string s;
    cin >> s;
    for (int i = 0; i < 1000; i++) {
        if (i % 8 == 0) {
            string x = to_string(i);
            if (is_substr(s, x)) {
                cout << "YES\n";
                cout << i;
                return;
            }
        }
    }
    cout << "NO\n";
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