#include <bits/stdc++.h>
#include <cmath>
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
int k, n, m;
char Map[35][35][35];
bool vis[35][35][35];
struct node{
    int h, x, y;
    int step;
    node(int hh, int xx, int yy, int st = 0) : h(hh), x(xx), y(yy), step(st) {}
    node operator+(int dir[3]) {
        return node(h + dir[0],x + dir[1], y + dir[2]);
    }
};
int dir[6][3] = {{0, -1 , 0}, {0, 1 , 0}, {0, 0 , -1}, {0, 0 , 1}, {1, 0 , 0}, {-1, 0 , 0}};
bool isLegal(node x) {
    return (x.h >= 0 && x.h < k) && (x.x >= 0 && x.x < n) && (x.y >= 0 && x.y < m);
}
void solve() {

    while (cin >> k >> n >> m && k) {
        queue<node> qu;
        memset(vis, 0 ,sizeof(vis));
        for (int h = 0; h < k; h ++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cin >> Map[h][i][j];
                    if (Map[h][i][j] == 'S') {
                       qu.push(node(h, i, j, 0));
                       vis[h][i][j] = true; 
                    }
                }
            }
        }
        for (int h = 0; h < k; h ++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cerr << Map[h][i][j] << " ";
                }
                cerr << "\n";
            }
            cerr << "\n\n";
        }
        bool success = false;
        while (!qu.empty()) {
            node now = qu.front();
            
            qu.pop();
            debug(now.h, now.x, now.y, Map[now.h][now.x][now.y]);
            if (Map[now.h][now.x][now.y] == 'E') {
                success = true;
                cout << "Escaped in " <<  now.step <<  " minute(s).\n";
                break;
            }
            for (int i = 0; i < 6; i++) {
                node nxt = now + dir[i];
                
                nxt.step = now.step + 1;
                if (isLegal(nxt) && (Map[nxt.h][nxt.x][nxt.y] == '.' || Map[nxt.h][nxt.x][nxt.y] == 'E') &&  !vis[nxt.h][nxt.x][nxt.y] ) {
                    qu.push(nxt);
                    vis[nxt.h][nxt.x][nxt.y] = true;
                }
            }
        }
        if (!success) {
            cout << "Trapped!\n";
        }
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