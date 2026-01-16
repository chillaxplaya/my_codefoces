#include <bits/stdc++.h>
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
char xiangqi[11][10];
int vis[11][10];
struct node{
    char c;
    int x, y;
    node() {}
    node(char c1, int x1, int y1) : c(c1) , x(x1), y(y1) {}
};
bool mapLegal(int x, int y) {
    if(x >= 1 && x <= 10 && y >= 1 && y <=9) 
        return true;
    return false;
}
void resolveG(node &a) {
    int x = a.x;
    int y = a.y;
    x--;
    while (mapLegal(x, y)) {
        vis[x][y] = 1;
        if (xiangqi[x--][y] != 0) {
            break;
        }
    }
}
void resolveR(node &a) {
    int x = a.x - 1;
    int y = a.y;
    while (mapLegal(x, y)) {
        vis[x][y] = 1;
        if (xiangqi[x--][y] != 0) {
            break;
        }
    }
    x = a.x + 1;
    y = a.y;
    while (mapLegal(x, y)) {
        vis[x][y] = 1;
        if (xiangqi[x++][y] != 0) {
            break;
        }
    }
    x = a.x;
    y = a.y - 1;
    while (mapLegal(x, y)) {
        vis[x][y] = 1;
        if (xiangqi[x][y--] != 0) {
            break;
        }
    }
    x = a.x;
    y = a.y + 1;
    while (mapLegal(x, y)) {
        vis[x][y] = 1;
        if (xiangqi[x][y++] != 0) {
            break;
        }
    }
}
void resolveH(node &a) {
    int x = a.x;
    int y = a.y;
    if (mapLegal(x - 1, y) && xiangqi[x - 1][y] == 0) {
        if (mapLegal(x - 2, y - 1)) {
            vis[x - 2][y - 1] = 1;
        }
        if (mapLegal(x - 2, y + 1)) {
            vis[x - 2][y + 1] = 1;
        }
    }
    if (mapLegal(x + 1, y) && xiangqi[x + 1][y] == 0) {
        if (mapLegal(x + 2, y - 1)) {
            vis[x + 2][y - 1] = 1;
        }
        if (mapLegal(x + 2, y + 1)) {
            vis[x + 2][y + 1] = 1;
        }
    }
    if (mapLegal(x, y - 1) && xiangqi[x][y - 1] == 0) {
        if (mapLegal(x - 1, y - 2)) {
            vis[x - 1][y - 2] = 1;
        }
        if (mapLegal(x + 1, y - 2)) {
            vis[x + 1][y - 2] = 1;
        }
    }
    if (mapLegal(x, y + 1) && xiangqi[x][y + 1] == 0) {
        if (mapLegal(x - 1, y + 2)) {
            vis[x - 1][y + 2] = 1;
        }
        if (mapLegal(x + 1, y + 2)) {
            vis[x + 1][y + 2] = 1;
        }
    }
}
void resolveC(node &a) {
    int x = a.x;
    int y = a.y;
    x--;
    int nx = -1, ny = -1;
    while (mapLegal(x, y)) {
        if (xiangqi[x][y] != 0) {
            nx = x - 1;
            ny = y;
            while (mapLegal(nx, ny)) {
                vis[nx][ny] = 1;
                if (xiangqi[nx--][ny] != 0) {
                    break;
                }
            }
            break;
        }
        x--;
    }
    x = a.x;
    y = a.y;
    x++;
    nx = -1, ny = -1;
    while (mapLegal(x, y)) {
        if (xiangqi[x][y] != 0) {
            nx = x + 1;
            ny = y;
            while (mapLegal(nx, ny)) {
                vis[nx][ny] = 1;
                if (xiangqi[nx++][ny] != 0) {
                    break;
                }
            }
            break;
        }
        x++;
    }
    x = a.x;
    y = a.y;
    y++;
    nx = -1, ny = -1;
    while (mapLegal(x, y)) {
        if (xiangqi[x][y] != 0) {
            nx = x;
            ny = y + 1;
            while (mapLegal(nx, ny)) {
                vis[nx][ny] = 1;
                if (xiangqi[nx][ny++] != 0) {
                    break;
                }
            }
            break;
        }
        y++;
    }
    x = a.x;
    y = a.y;
    y--;
    nx = -1, ny = -1;
    while (mapLegal(x, y)) {
        if (xiangqi[x][y] != 0) {
            nx = x;
            ny = y - 1;
            while (mapLegal(nx, ny)) {
                vis[nx][ny] = 1;
                if (xiangqi[nx][ny--] != 0) {
                    break;
                }
            }
            break;
        }
        y--;
    }
}
void resolve(node &a) {
    if (a.c == 'G') {           //帅
        resolveG(a);
    } else if(a.c == 'R') {     //车
        resolveR(a);
    } else if(a.c == 'H') {     //马
        resolveH(a);
    }  else if(a.c == 'C') {     //炮
        resolveC(a);
    } 
}
void printmap() {
    cerr << "  1234567890" << endl;
    for (int i = 1; i <=10 ;i++) {
        if(i < 10) cerr << " ";
        cerr << i;
        for (int j = 1; j <= 9; j++) {
            cerr << (vis[i][j] ? "#" : " ");
        }
        cerr << endl;
    }
    cerr << "  ----------" << endl;
}
bool legal9(int x, int y) {
    if (x >= 1 && x <= 3 && y >=4 && y <= 6) {
        return true;
    }
    return false;
}
bool judgeWin(int x, int y) {
    bool a1 = (!legal9(x + 1, y) || vis[x + 1][y]);
    debug(legal9(x + 1, y),vis[x + 1][y]);
    bool a2 = (!legal9(x - 1, y) || vis[x - 1][y]);
    bool a3 = (!legal9(x, y + 1) || vis[x][y + 1]);
    bool a4 = (!legal9(x, y - 1) || vis[x][y - 1]);
    debug(a1,a2,a3,a4);
    if(a1 && a2 && a3 && a4) return true;
    
    return false;
}
bool feiG(int x,int y) {
    x++;
    while (mapLegal(x, y)) {
        if(xiangqi[x][y] == 'G') {
            return true;
        }
        if(xiangqi[x][y] != 0) {
            return false;
        }
        x++;
    }
    return false;
}
void solve() {
    int n, gx, gy, x, y;
    char c;
    while(cin >> n >> gx >> gy && n) {
        memset(xiangqi, 0, sizeof(xiangqi));
        memset(vis, 0, sizeof(vis));
        vector<node> save;
        for (int i = 0; i < n; i++) {
            cin >> c >> x >> y;
            save.push_back(node(c, x, y));
            xiangqi[x][y] = c;
        }
        for (int i = 0; i < n; i++) {
            resolve(save[i]);            
        }
        // printmap();
        if(judgeWin(gx, gy) && !feiG(gx, gy)) cout << "YES\n";
        else cout << "NO\n";
    }
}
//（字符 'G' 代表帅，'R' 代表车，'H' 代表马，'C' 代表炮）
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}