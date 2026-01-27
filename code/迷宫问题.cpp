#include <bits/stdc++.h>
#include <queue>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n) \
    cerr << "[" << #a << "] = {"; \
    for (int i = 0; i < (n); i++) cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";


#define all(x) (x).begin(), (x).end()
#define ll long long
int Map[5][5];
int pre[25];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int vis[5][5];
void solve() {
    auto getId = [](int x, int y) {
        return x * 5 + y;
    };
    auto getXy = [](int id) {
        return pair<int, int>(id / 5, id % 5);
    };
    auto inBd = [](int x, int y) {
        return x >= 0 && x < 5 && y >= 0 && y < 5;
    };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> Map[i][j];
        }
    }
    queue<int> qu;
    qu.push(0);
    pre[0] = -1;
    vis[0][0] = 1;
    while (!qu.empty()) {
        int nid = qu.front();
        qu.pop();
        pair<int, int> nxy = getXy(nid);
        for (int i = 0; i < 4; i++) {
            int nx = nxy.first + dir[i][0];
            int ny = nxy.second + dir[i][1];
            if (inBd(nx, ny) && Map[nx][ny] == 0 && !vis[nx][ny]) {
                int nxid = getId(nx, ny);
                pre[nxid] = nid;
                qu.push(nxid);
                vis[nx][ny] = 1;
            }
        }
    }
    stack<int> anss;
    int i = 24;
    do {
        anss.push(i);
        debug(i);
        i = pre[i];
    } while(i != -1);

    while (!anss.empty()) {
        pair<int, int> nxy = getXy(anss.top());
        cout << "(" << nxy.first <<", " << nxy.second << ")\n";
        anss.pop();
    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}