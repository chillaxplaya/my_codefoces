/*
D - Take ABC 2
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc447/tasks/abc447_d
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
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'A') {
            a++;
        } else if (s[i] == 'B') {
            b = min(b + 1, a);
        } else {
            c = min(c + 1, b);
        }
    }
    cout << c;
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