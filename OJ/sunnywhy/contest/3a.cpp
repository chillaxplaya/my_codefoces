/*
${title}
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
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
bool need[5];
bool inclu[26];
int res[5];
bool checkl(int *a, const pair<string, string> &b) {
    rep(i, 5) {
        for (int j = i + 1; j < 5; j++) {
            if (a[i] == a[j]) return false;
        }
    }
    rep(i, 5) {
        if (b.second[i] == '2' || b.second[i] == '0') continue;
        if (b.second[i] == '1') {
            bool ok = false;
            rep(j, 5) {
                if (j == i) {
                    if (a[j] == b.first[i] - 'a') {
                        return false;
                    }
                    continue;
                }
                if (a[j] == b.first[i] - 'a') {
                    ok = true;
                }
            }
            if (!ok) return false; 
        }
    }
    return true;
}
void dfs(vector<pair<string, string>> &a, int h) {
    if (h == 5) {
        for (auto &e : a) {
            if (!checkl(res, e)) {
                return;
            }
        }
        rep(i, 5) cout << (char)(res[i] + 'a');
        cout << endl;
        return;
    }
    if (!need[h]) {
        dfs(a, h + 1);
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (!inclu[i]) continue;
        res[h] = i;
        dfs(a, h + 1);
    }
}
void justdoit() {
    int n;
    cin >> n;
    vector<pair<string, string>> a(n);
    rep(i, 5) {
        need[i] = true;
    }
    rep(i, 26) {
        inclu[i] = true;
    }

    rep(i, n) {
        cin >> a[i].first >> a[i].second;
        rep(j, 5) {
            if (a[i].second[j] == '2') {
                need[j] = false;
                res[j] = a[i].first[j] - 'a';
            } else if (a[i].second[j] == '0') {
                inclu[a[i].first[j] - 'a'] = false;
            }
        }
    }

    dfs(a, 0);
}
int main() {
    // srand(time(0));
    // ios::sync_with_stdio(0);
    // cout.tie(0), cin.tie(0);
    justdoit();
    return 0;
}