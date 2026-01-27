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
int T = 0;
int hmap[11][11];
int vmap[11][11];
int n, k;
void printm() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cerr << hmap[i][j];
        }
        cerr << endl;
    }

    cerr << endl;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cerr << vmap[i][j];
        }
        cerr << endl;
    }
}
bool judgesq(int x, int y, int sz) {
    if (hmap[x][y + sz] - hmap[x][y] != sz) return false;
    if (vmap[x + sz][y] - vmap[x][y] != sz) return false;
    if (hmap[x + sz][y + sz] - hmap[x + sz][y] != sz) return false;
    if (vmap[x + sz][y + sz] - vmap[x][y + sz] != sz) return false;
    return true;
}
void solve() {
    if(T)cout << "\n**********************************\n\n" ;
    cout << "Problem #" << ++T << "\n\n";
    memset(hmap, 0, sizeof(hmap));
    memset(vmap, 0, sizeof(vmap));

    char c;
    int x, y;
    vector<pair<int, int>> hl;
    vector<pair<int, int>> vl;
    for (int i = 0; i < k; i++) {
        cin >> c >> x >> y;
        if(c == 'H') hl.push_back({x, y});
        else if (c == 'V') vl.push_back({x, y});
    }
    sort(all(hl));
    sort(all(vl));
    for (auto e : hl) {
        if (e.second <= n) {
            hmap[e.first][e.second + 1] = hmap[e.first][e.second] + 1;
        }
        debug(e);
    }
    for (auto e : vl) {
        swap(e.first, e.second);
        if (e.first < n) {
            vmap[e.first + 1][e.second] = vmap[e.first][e.second] + 1;
        }
    }
    debug(hl.size(), vl.size());
    printm();
    bool have = false;
    for (int sz = 1; sz < n; sz++) {
        int conut = 0;
        int bound = n - sz;
        for (int i = 1; i <= bound; i++) {
            for (int j = 1; j <= bound; j++) {
                if(judgesq(i, j, sz)) {
                    conut++;
                }
            }
        }
        if(conut) {
            cout << conut << " square (s) of size " << sz << "\n";
            have = true;
        }
        

    }
    if(!have) cout << "No completed squares can be found.\n";
}

int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    // cin >> T;
    while(cin >> n >> k) solve();
    return 0;
}