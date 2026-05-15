/*
D. 加法映射等式
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-06 19:47:52
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
vector<int> alp;
vector<int> wi;
vector<int> wi1;
vector<int> defy;
int choose[26];
int res = 0;
int nvis[20];
void dfs(int k) {
    if (k == alp.size()) {
        
        int ares = 0;
        int bres = 0;
        
        for (int i = 0; i < 26; i++) {
            if (choose[i]) {
                ares += choose[i] * wi[i];
            }
        }
        for (int i = 0; i < 26; i++) {
            if (choose[i]) {
                bres += choose[i] * wi1[i];
            }
        }

        if (ares == bres) {
            debug(ares,bres);
            res++;
        }
        return;
    }
    if (!defy[alp[k]]) {
        if (!nvis[0]){
            choose[alp[k]] = 0;
            nvis[0] = 1;
            dfs(k + 1);
            nvis[0] = 0;
        }
            
    }
    for (int i = 1; i <= 9; i++) {
        
        if (!nvis[i]){
            choose[alp[k]] = i;
            nvis[i] = 1;
            dfs(k + 1);
            nvis[i] = 0;
        }
    }
}
void justdoit() {
    int n;
    vector<int> vis(26, 0);
    vector<vector<int>> cnt(26, vector<int>(10, 0));
    vector<vector<int>> cnt1(26, vector<int>(10, 0));
    defy.resize(26);
    fill(all(defy), 0);
    wi.resize(26);
    wi1.resize(26);
    cin >> n;
    string s;
    rep(o, n - 1) {
        cin >> s;
        defy[s[0] - 'A'] = 1;
        reverse(all(s));
        for (int i = 0; i < s.size(); i++) {
            if (!vis[s[i] - 'A']) {
                vis[s[i] - 'A'] = 1;
                alp.push_back(s[i] - 'A');
            }
            cnt[s[i] - 'A'][i]++;
        }
    }
    cin >> s;
    defy[s[0] - 'A'] = 1;
    reverse(all(s));
    for (int i = 0; i < s.size(); i++) {

        if (!vis[s[i] - 'A']) {
            vis[s[i] - 'A'] = 1;
            alp.push_back(s[i] - 'A');
        }
        cnt1[s[i] - 'A'][i]++;
    }
    
    sort(all(alp));
    for (auto &e : alp) {
        int cntt = 0;
        int pre = 1;
        for (int i = 0; i < cnt[e].size(); i++) {
            cntt += (cnt[e][i] * pre);
            pre *= 10;
        }
        wi[e] = cntt;
    }
    for (auto &e : alp) {
        int cntt = 0;
        int pre = 1;
        for (int i = 0; i < cnt1[e].size(); i++) {
            cntt += (cnt1[e][i] * pre);
            pre *= 10;
        }
        wi1[e] = cntt;
    }
    dfs(0);
    cout << res;
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