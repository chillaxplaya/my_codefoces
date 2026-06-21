/*
004 - Cross Sum（★2）
Time Limit: 5000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/typical90/tasks/typical90_d
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

void justdoit() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> grid(h, vector<int>(w));
    for (auto &line : grid) {
        for (auto &ele : line) {
            cin >> ele;
        }
    }
    vector<int> linecnt(h);
    vector<int> colcnt(w);
    for (int i = 0; i < h; i++) {
        int sum = 0;
        for (int j = 0; j < w; j++) {
            sum += grid[i][j];
        }
        linecnt[i] = sum;
    }
    for (int i = 0; i < w; i++) {
        int sum = 0;
        for (int j = 0; j < h; j++) {
            sum += grid[j][i];
        }
        colcnt[i] = sum;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (j) cout << ' ';
            cout << linecnt[i] + colcnt[j] - grid[i][j];
        }
        cout << endl;
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