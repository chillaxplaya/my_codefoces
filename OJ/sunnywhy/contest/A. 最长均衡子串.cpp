/*
A. 最长均衡子串
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-08 19:31:41
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
bool iscnt(string s, int l, int r) {
    vector<int> cnt(26, 0);
    int maxc = 0;
    for (int i = l; i <= r; i++) {
        cnt[s[i] - 'a']++;
        maxc = max(maxc, cnt[s[i] - 'a']);
    }
    for (int i = 0; i < 26; i++) {
        if (!cnt[i]) continue;
        if (cnt[i] != maxc) return false;
    }
    return true;
}
void justdoit() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (iscnt(s, i, j)) {
                res = max(res, j - i + 1);
            }
        }
    }
    cout << res;
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