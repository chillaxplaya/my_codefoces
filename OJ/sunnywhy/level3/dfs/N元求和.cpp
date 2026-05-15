/*
N元求和
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-11 15:53:50
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
int n;
vector<int> res;
vector<int> a;
void dfs(int k, int sum) {
    if (k == n) {
        res.push_back(sum);
        return;
    }
    int x;
    x = a[k];
    dfs(k + 1, sum + x);
    dfs(k + 1, sum - x);
}
void justdoit() {
    
    cin >> n;
    a.resize(n);
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    dfs(0, 0);
    sort(all(res));
    res.erase(unique(all(res)), res.end());
    for (auto &e : res) {
        cout << e << endl;
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