/*
兵棋肉鸽III
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-16 00:25:40
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

int cnt[30];
vector<vector<int>> a;
char grid[105][105];
int vis[105][105];
int n, h, w;
int remcnt[30];
int getsize[30];
bool okput(char c, int s, int n, int m) {
    if (s == 7) m--;
    for (int i = n; i < n + 2; i++) {
        for (int j = m; j < m + 2; j++) {
            if ((1 << (3 - ((i - n) * 2 + (j - m)))) & s) {
                if (grid[i][j] != c || vis[i][j]) {
                    return false;
                }
            }
        }
    }
    return true;
}
bool put01(int s, int n, int m, int state) {
    if (s == 7) m--;
    for (int i = n; i < n + 2; i++) {
        for (int j = m; j < m + 2; j++) {
            if ((1 << (3 - ((i - n) * 2 + (j - m)))) & s) {
                vis[i][j] = state;
            }
        }
    }
    return true;
}
bool dfs(char c, int rem, int n, int m) {
    if (rem == 0) {
        return true;
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (grid[i][j] == c && !vis[i][j]) {
                if (okput(c, a[c - 'A'][0], i, j)) {
                    put01(a[c - 'A'][0], i, j, 1);
                    if (dfs(c, rem - getsize[c - 'A'], i, j)) {
                        return true;
                    }
                    put01(a[c - 'A'][0], i, j, 0);
                }
                if (a[c - 'A'].size() > 1 && okput(c, a[c - 'A'][1], i, j)) {
                    put01(a[c - 'A'][1], i, j, 1);
                    if (dfs(c, rem - getsize[c - 'A'], i, j)) {
                        return true;
                    }
                    put01(a[c - 'A'][1], i, j, 0);
                }
                return false;
            }
        }
    }
    return false;
}
void justdoit() {
    srand(time(0));
    char c;
    string t;
    a.resize(30);
    cin >> n;
    map<int, int> rot;
    rot[13] = 7;
    rot[7] = 11;
    rot[11] = 14;
    rot[14] = 13;
    rot[15] = 15;
    for (int i = 0; i < n; i++) {
        cin >> c;
        cnt[c - 'A'] = 1;
        cin >> h >> w;
        if (h * w == 2) {
            if (h == 1 && w == 2) {
                a[c - 'A'].push_back(12);
            } else {
                a[c - 'A'].push_back(10);
            }
        } else if (h == 1 && w == 1) {
            a[c - 'A'].push_back(8);
        }
        int state = 0;
        for (int i = 0; i < h; i++) {
            cin >> t;
            if (h == w && h == 2) {
                state <<= 1;
                state += (t[0] == c);
                state <<= 1;
                state += (t[1] == c);
            }
        }
        if (h == w && h == 2) {
            a[c - 'A'].push_back(state);
            // if (state != rot[state])
                // a[c - 'A'].push_back(rot[state]);
        }
        if (a[c - 'A'][0] == 15) {
            getsize[c - 'A'] = 4;
        } else if (a[c - 'A'][0] == 8) {
            getsize[c - 'A'] = 1;
        } else if (a[c - 'A'][0] == 10 || a[c - 'A'][0] == 12) {
            getsize[c - 'A'] = 2;
        } else {
            getsize[c - 'A'] = 3;
        }
    }
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> grid[i][j];
            if (grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
                remcnt[grid[i][j] - 'A']++;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            if (getsize[i] == 1) continue;
            if (remcnt[i] % getsize[i] != 0  || !dfs((char)(i + 'A'), remcnt[i], 0, 0)) {
                cout << "No";
                return;
            }
        }
    }
    cout << "Yes";

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