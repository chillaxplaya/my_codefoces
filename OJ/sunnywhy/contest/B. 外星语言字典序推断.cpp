/*
B. 外星语言字典序推断
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-08 19:39:59
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
int k;
void justdoit() {

    char c;
    int n;
    cin >> c >> n;
    vector<string> s(n);
    vector<vector<int>> g(26);
    vector<int> inn(26);
    vector<int> outn(26);
    k = c - 'a';
    int maxl = 0;
    for (auto &e : s) {
        cin >> e;
        maxl = max(maxl, (int)e.size());
    }
    for (int i = 1; i < n; i++) {
        int j = 0, k = 0;
        while(j < s[i - 1].size() && k < s[i].size() && s[i - 1][j] == s[i][k]) {
            j++;
            k++;
        }
        bool found = false;
        if (j < s[i - 1].size() && k < s[i].size() && s[i - 1][j] != s[i][k]) {
            bool conut = false;
            found = true;
            for (auto &e : g[s[i - 1][j] - 'a']) {
                if (e == s[i][k] - 'a') conut = true;
            }
            if (1) {
                g[s[i - 1][j] - 'a'].push_back(s[i][k] - 'a');
                inn[s[i][k] - 'a']++;
            }
        }
        if (!found && s[i - 1].size() > s[i].size()) {
            cout << "IMPOSSIBLE";
            return;
        } 
    }
    vector<int> tinn(inn);
    vector<int> vis(26, 0);
    queue<int> qu;
    bool am = false;
    for (int i = 0; i <= (c - 'a'); i++) {
        if (tinn[i] == 0) {
            qu.push(i);
            debug(i);
        }
    }
    if (qu.size() == 0) {
        cout << "IMPOSSIBLE";
        return;
    }

    while (!qu.empty()) {
        int start = qu.front();
        if (qu.size() >= 2) {
            am = true;
        }
        qu.pop();
        if (vis[start]) {
            cout << "IMPOSSIBLE";
            return;
        }
        vis[start] = 1;
        for (auto &e : g[start]) {
            tinn[e]--;
            if (tinn[e] == 0) {
                qu.push(e);
            }
        }
    }

    vector<int> res;
    for (int i = 0; i <= (c - 'a'); i++) {
        if (inn[i] == 0) {
            qu.push(i);
            // res.push_back(i);
        }
    }
    while (!qu.empty()) {
        int start = qu.front();
        qu.pop();
        res.push_back(start);
        for (auto &e : g[start]) {
            inn[e]--;
            if (inn[e] == 0) {
                qu.push(e);
            }
        }
    }
    if (res.size() < (c - 'a') + 1) {
        cout << "IMPOSSIBLE" ;
        return;
    }
    if (am) {
        cout << "AMBIGUOUS" ;
        return;
    }
    for (int i = 0; i <= (c - 'a'); i++) {
        cout << (char)(res[i] + 'a');
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