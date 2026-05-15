/*
受到祝福的平方
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-11 17:48:18
*/
#include <bits/stdc++.h>
#include <cstddef>
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
unordered_set<int> dic;
ll getNum[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int n;
bool dfs(ll num, int k) {
    if (n == k) return true;
    for (int i = 1; i <= n - k; i++) {
        
        if (dic.count(num % getNum[i]) && dfs(num / getNum[i], k + i)) {
            return true;
        }
    }
    return false;
}
void justdoit() {
    string s;
    cin >> s;
    n = s.size();
    ll x = stoi(s);
    for (int i = 1; i * i <= 1000000000; i++) {
        dic.insert(i * i);
    }
    if (dfs(x, 0)) {
        cout << "Yes";
    } else {
        cout << "No";
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