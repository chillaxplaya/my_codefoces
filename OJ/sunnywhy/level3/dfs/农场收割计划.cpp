/*
农场收割计划
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-13 13:39:34
user: playa
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
int hw[105][105];
int vis[105][105];
char dirchar[4] = {'D', 'L', 'R', 'U'};
int dir[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
int h, w, n;
vector<char> res;
bool dfs(int x, int y, int k) {
    vis[x][y] = 1;
    if (k == 0) {
        return true;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && !hw[nx][ny] && !vis[nx][ny] && dfs(nx, ny, k - 1)) {
            res.push_back(dirchar[i]);
            return true;
        }
    }
    vis[x][y] = 0;
    return false;

}
void justdoit() {

    int x, y;
    cin >> h >> w >> n;
    rep(i, n) {
        cin >> x >> y;
        hw[x][y] = 1;
    }
    dfs(0, 0, (h * w - n + 1) / 2 - 1);
    reverse(all(res));
    for (auto &e : res) {
        cout << e;
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