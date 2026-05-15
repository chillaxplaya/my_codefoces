/*
C. 树形分级文件系统
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-05 20:06:08
*/
#include <bits/stdc++.h>
#include <unordered_map>
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
unordered_map<string, int> dic;
int idx = 0;
vector<string> name;
int getID(string s) {
    if (dic.count(s)) return dic[s];
    else {
        name.push_back(s);
        return dic[s] = idx++;
    }
}
int n;
vector<vector<int>> g;
vector<vector<int>> gg;
vector<int> wi;
vector<int> hold;
vector<int> pa;
vector<int> leaf;

void justdoit() {
    cin >> n;
    wi.resize(n);
    g.resize(n);
    hold.resize(n);
    pa.resize(n);
    gg.resize(n);
    fill(all(pa), -1);
    string node, par;
    int w = 0;
    rep(i, n) {
        cin >> node >> par >> w;
        int id1 = getID(node);
        int id2 = getID(par);
        wi[id1] = w;
        hold[id1] = -1;
        
        if (w > 0) {
            leaf.push_back(id1);
        }
        if (id1 != id2){
            pa[id1] = id2;
            gg[id2].push_back(id1);
        }
            
    }
    vector<int> vis(n, 0);
    vector<int> maxz(n, -1);
    vector<int> zd(n, -1);
    for (auto &e : leaf) {
        int x = e;
        while(1) {
            if (x == -1) break;
            if (wi[e] > maxz[x]) {
                zd[x] = e;
                maxz[x] = wi[e];
            } else if (wi[e] == maxz[x]) {
                zd[x] = -1;
                maxz[x] = wi[e];
            }
            
            x = pa[x];
        }
    }
    for (auto &e : leaf) {
        string res;
        int x = e;
        while(1) {
            if (x == -1) break;
            if (zd[x] != -1 && wi[e] == maxz[x]) {
                res = name[x];
            }
            x = pa[x];
        }
        cout << res << endl;
    }

    // for (int i = 0; i < n; i++) {
    //     debug(i,g[i]);
    //     sort(all(g[i]), greater<pi>());
    //     if (g[i].size() == 0 || (g[i].size() >= 2 && g[i][0].first == g[i][1].first)) {
    //         continue;
    //     }
        
    //     if (!vis[g[i][0].second])
    //         res.push_back(make_pair(g[i][0].second, name[i]));
    //         // cout << name[i] << endl;
    //     vis[g[i][0].second] = 1;
    // }
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