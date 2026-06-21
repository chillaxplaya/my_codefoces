/*
A - Strong Word
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc445/tasks/abc445_a
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
//#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

void justdoit() {
    string s;
    cin >> s;
    cout << (s[0] == s.back() ? "Yes" : "No");
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--)
        justdoit();
    return 0;
}