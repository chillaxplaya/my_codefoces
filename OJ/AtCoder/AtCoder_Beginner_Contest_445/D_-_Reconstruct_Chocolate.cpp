/*
D - Reconstruct Chocolate
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc445/tasks/abc445_d
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
    int h, w, n;
    cin >> h >> w >> n;
    vector<pi> hw(n);
    for (auto &[h1, h2] : hw) {
        cin >> h1 >> h2;
    }
    vector<int> hi(n);
    vector<int> wi(n);
    vector<int> vis(n, 0);
    iota(all(hi), 0);
    iota(all(wi), 0);
    debug("...");
    sort(all(hi), [&](const int &a, const int &b) {
        return hw[a].first > hw[b].first;
    });
    sort(all(wi), [&](const int &a, const int &b) {
        return hw[a].second > hw[b].second;
    });
    int idxh = 0, idxw = 0;
    vector<pi> res(n);
    debug(hi);
    debug(wi);
    while (h > 0 && w > 0) {
        while(vis[hi[idxh]]) idxh++;
        while(vis[wi[idxw]]) idxw++;
        if (hw[hi[idxh]].first == h) {
            // cout << w - hw[hi[idxh]].second + 1 << " " << 1 << endl;
            res[hi[idxh]].second = w - hw[hi[idxh]].second + 1;
            res[hi[idxh]].first = 1;
            debug(res[hi[idxh]]);
            w -= hw[hi[idxh]].second;
            vis[hi[idxh]] = 1;
            idxh++;
        } else if (hw[wi[idxw]].second == w) {
            // cout << 1 << " " << h - hw[hi[idxh]].first + 1 << endl;
            res[wi[idxw]].second = 1;
            res[wi[idxw]].first = h - hw[wi[idxw]].first + 1;
            debug(res[wi[idxw]]);
            h -= hw[wi[idxw]].first;
            vis[wi[idxw]] = 1;
            idxw++;
        }
    }
    for (auto &[resx, resy] : res) {
        cout << resx << " " << resy << endl;
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