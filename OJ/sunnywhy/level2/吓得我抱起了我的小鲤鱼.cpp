/*
吓得我抱起了我的小鲤鱼
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-02 16:07:35
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
void dfs(int k) {
    if (k == 0) {
        cout << "我的小鲤鱼";
        return;
    }
    cout << "抱着";
    dfs(k - 1);
    cout << "的我";
}
void justdoit() {
    int n;
    cin >> n;
    cout << "吓得我抱起了";
    dfs(n);
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