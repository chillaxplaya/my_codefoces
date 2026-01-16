#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
int now = 0;
pair<int, int> dir[8] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
char b[] = {'W','B'};

#define all(x) (x).begin(), (x).end()
#define ll long long
string disk[9];
bool fc = true;
void printdisk() {

    for (int i = 1; i < 9; i++) {
        string t = disk[i].substr(1 , 8);
        cout << t << "\n";
    }
}
bool legaldisk(int x, int y) {
    return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}
int findB(int x, int y, const pair<int, int> dir) {
    x += dir.first;
    y += dir.second;
    while(legaldisk(x, y)){
        if (disk[x][y] == b[now]) {
            return (x - 1) * 8 + y;
            
        }
        if (disk[x][y] == '-') {
            return 0;
        }
        x += dir.first;
        y += dir.second;
    }
    return 0;
}
vector<int> findB(int x,int y) {
    vector<int> res;
    for (int i = 0; i < 8; i++) {
        int nx = x + dir[i].first;
        int ny = y + dir[i].second;
        if (legaldisk(nx, ny) && disk[nx][ny] == b[1 - now]) {
            int f = findB(x, y, dir[i]);
            if (f) res.push_back(f); 
        }
    }
    return res;
}
void cmdL() {
    vector<int> res;
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (disk[i][j] == '-') {
                vector<int> bres = findB(i, j);
                if(bres.size() > 0) {
                    res.push_back((i - 1) * 8 + j - 1);
                }
                    
            }
        }
    }
    if(res.size() > 0) {
        for (int i = 0; i < res.size(); i++) {
            if(i) cout <<" ";
            cout << "(" << res[i] / 8 + 1 << "," << res[i] % 8 + 1<< ")";
        }
    } else {
        cout << "No legal move.";
    }
    cout << "\n";
}
void cmdM(string cmd) {
    int x = cmd[1] - '0';
    int y = cmd[2] - '0';
    disk[x][y] = b[now];
    for (int i = 0; i < 8; i++) {
        int nx = x + dir[i].first;
        int ny = y + dir[i].second;
        if (legaldisk(nx, ny) && disk[nx][ny] == b[1 - now] && findB(x, y, dir[i])) {
            while(legaldisk(nx, ny) && disk[nx][ny] == b[1 - now]) {
                disk[nx][ny] = b[now];
                nx = nx + dir[i].first;
                ny = ny + dir[i].second;
            }
        }
    }
}
pair<int, int> countBW() {
    pair<int, int> BW;
    BW.first = 0;
    BW.second = 0;
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if(disk[i][j] == 'B') BW.first++;
            if(disk[i][j] == 'W') BW.second++;
            
        }
    }
    return BW;
}
bool haveLegalmove() {
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (disk[i][j] == '-') {
                vector<int> bres = findB(i, j);
                if(bres.size() > 0) {
                    return true;
                }
                    
            }
        }
    }
    return false;
}
void solve() {
    if(!fc) cout << "\n";
    fc = false;
    char c;
    for (int i = 1; i < 9; i++) {
        cin >> disk[i];
        disk[i] = " " + disk[i];
    }
    cin >> c;
    if (c == 'W') {
        now = 0;
    } else {
        now = 1;
    }
    string cmd;
    while (cin >> cmd && cmd[0] != 'Q') {
        switch (cmd[0]) {
            case 'L':
                cmdL();
                // printdisk();
                break;
            case 'M': {
                if(!haveLegalmove()) now = 1 - now;
                cmdM(cmd);
                now = 1 - now;
                pair<int, int> ans = countBW();
                cout << "Black -" << setw(3) << ans.first 
                    << " White -" << setw(3) << ans.second << "\n";
                
                // printdisk();
                break;
            }
            default:
                break;
        }
    }
    printdisk();

}
int main() {
    // srand(time(0));
    // ios::sync_with_stdio(0);
    // cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}