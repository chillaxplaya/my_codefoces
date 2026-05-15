/*
加号之和
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-11 16:45:48
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
int getNum[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define endl '\n'
int n;
ll ans = 0;
void dfs(int numrem, int rem, int sum) {
    if (rem == 0) {
        ans += sum;
        return;
    }
    debug(numrem);
    for (int i = 1; i <= rem; i++) {
        dfs(numrem / getNum[i], rem - i, sum + numrem % getNum[i]);
    }
}
void justdoit() {
    string s;
    cin >> s;
    n = s.size();
    int x = stoi(s);
    dfs(x, n, 0);
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