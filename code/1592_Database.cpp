#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n)                                           \
    cerr << "[" << #a << "] = {";                                 \
    for (int i = 0; i < (n); i++) cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

#define all(x) (x).begin(), (x).end()
#define ll long long
int a[10005][15];
map<string, int> dic;
int idx = 0;
int getdic(string s) {
    if (dic.count(s))
        return dic[s];
    else
        return dic[s] = idx++;
}
void getinrow(string s, int i) {
    debug(s);
    string ts;
    int index = 0;
    for (auto e : s) {
        if (e == ',') {
            debug(ts);
            a[i][index++] = getdic(ts);
            ts.clear();
            continue;
            
        }
        ts += e;
    }
    debug(ts);
    a[i][index++] = getdic(ts);
}
void solve() {
    int n, m;
    string row;
    
    while (cin >> n && cin >> m) {
        
        dic.clear();
        idx = 0;
        cin.get();
        debug(n, m);
        for (int i = 0; i < n; i++) {
            getline(cin, row);
            getinrow(row, i);
        }
        bool pnk = true;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                map<pair<int,int>, int> roow;
                for (int k = 0; k < n; k++) {
                    if (!pnk) break;
                    if (!roow.count({a[k][i],a[k][j]})) {
                        roow[{a[k][i],a[k][j]}] = k;
                    } else {
                        cout << "NO\n";
                        cout << roow[{a[k][i],a[k][j]}] + 1 
                            << " " << k + 1 << "\n";
                        cout << i + 1 << " " << j + 1 << "\n";
                        pnk = false;
                    }
                }
            }
        }
        if (pnk)
            cout << "YES\n";
    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}