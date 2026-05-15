/*
奶牛队列
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-08 18:32:16
*/
#include <bits/stdc++.h>
#include <unordered_map>
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) {
        cin >> e;
    }
    int ans = 0;
    unordered_map<int, int> pre;
    int left = 0;
    for (int right = 0; right < n; right++) {
        pre[a[right]]++;
        while (pre.size() > 2) {
            if (--pre[a[left]] == 0) {
                auto it = pre.find(a[left]);
                pre.erase(it);
            }
            left++;
        }
        for (auto &e : pre) {
            ans = max(ans, e.second);
        }
    }
    cout << ans;
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