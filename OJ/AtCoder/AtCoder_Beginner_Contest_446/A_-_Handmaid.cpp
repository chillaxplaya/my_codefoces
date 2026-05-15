/*
A - Handmaid
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc446/tasks/abc446_a
*/
#include <bits/stdc++.h>
#include <cctype>
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

void justdoit() {
    string s;
    cin >> s;
    s[0] = tolower(s[0]);
    cout << "Of" + s << endl;
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