/*
B. Little Girl and Game
Time Limit: 2000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/276/B
*/
#include <bits/stdc++.h>
#include <cstdio>
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
    char c;
    vector<int> cnt(26);
    while ((c = getchar()) != EOF && islower(c)) {
        cnt[c - 'a']++;
    }
    int oddcnt = 0;
    for (auto &e : cnt) {
        if (e % 2) {
            oddcnt++;
        }
    }
    if (oddcnt == 0) {
        cout << "First";
        return;
    }
    cout << ((oddcnt & 1) ? "First" : "Second");
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