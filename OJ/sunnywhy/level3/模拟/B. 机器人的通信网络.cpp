/*
B. 机器人的通信网络
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-05 19:55:07
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
typedef pair<int, int> pi;
int getdis(pi a, pi b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}
void justdoit() {
    int n;
    cin >> n;
    vector<pi> node(n);
    vector<int> dis(n);
    vector<int> vis(n, 0);
    for (auto &[x, y] : node) {
        cin >> x >> y;
    }
    dis[0] = 0;
    for (int i = 1; i < n; i++) {
        dis[i] = getdis(node[0], node[i]);
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int mindis = INF;
        int csn = -1;
        for (int j = 1; j < n; j++) {
            if (dis[j] < mindis && !vis[j]) {
                mindis = dis[j];
                csn = j;
            }
        }
        vis[csn] = 1;
        ans += mindis;
        for (int j = 1; j < n; j++) {
            if (!vis[j])
                dis[j] = min(dis[j], getdis(node[csn], node[j]));
        }
    }
    cout << ans * 2;
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