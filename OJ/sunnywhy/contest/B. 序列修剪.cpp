/*
B. 序列修剪
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-16 19:36:29
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

void justdoit() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int round = 1;
    rep(i, n) {
        if (s.size() < 4)
            break;
        if (round == 0) {
            int k = s.size() / 4;
            // rep(j, k) {
            //     s.pop_back();
            // }
            s = s.substr(0, s.size() - k);
        } else {
            int k = s.size() / 4;
            // rep(j, k) {
            //     s.erase(s.begin());
            // }
            s = s.substr(k, s.size() - k);
        }
        round = 1 - round;
    }
    cout << s;
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