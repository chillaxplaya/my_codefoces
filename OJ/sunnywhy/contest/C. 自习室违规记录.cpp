/*
C. 自习室违规记录
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-15 13:45:28
user: playa
*/
#include <bits/stdc++.h>
#include <functional>
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
unordered_map<string, int> group;
unordered_map<string, int> isset;
unordered_map<string, int> last_ilg;
int groupnum[1000005];
void justdoit() {
    int n, k, a;
    string name;
    cin >> n >> k;
    rep(i, k) {
        int m;
        cin >> groupnum[i] >> m;
        rep(j, m) {
            cin >> name;
            group[name] = i;
            isset[name] = 0;
            last_ilg[name] = 0;
        }
    }
    
    int m;
    int cnt = 0;
    cin >> m;
    set<string> res;
    vector<string> resvec;
    rep(i ,m) {
        cin >> name;
        if (!group.count(name)) {
            res.insert(name);
            resvec.push_back(name);
            continue;
        }
        if (last_ilg[name]) {
            last_ilg[name] = 0;
            continue;
        }
        if (isset[name] == 0 && groupnum[group[name]] > 0 && n > 0) {
            isset[name] = 1;
            groupnum[group[name]]--;
            n--;
            continue;
        }
        if (isset[name] == 1) {
            isset[name] = 0;
            groupnum[group[name]]++;
            n++;
            continue;
        }
        res.insert(name);
        resvec.push_back(name);
        last_ilg[name] = 1;
    }
    cout << res.size() << endl;
    for (auto e : res) {
        cout << e << endl;
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