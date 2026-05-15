/*
${title}
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: https://sunnywhy.com/camp/3415/model/3613?itemId=4092
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
bool judge(string &s, int k) {
    int x = 0;
    int y = 0;
    int xwin = 0;
    int ywin = 0;
    for (auto &e : s) {
        if (e == 'X') {
            x++;
        } else {
            y++;
        }
        if (x == k) {
            x = 0;
            y = 0;
            xwin++;
        } else if (y == k) {
            x = 0;
            y = 0;
            ywin++;
        }
    }
    if (xwin > ywin) {
        return true;
    }
    return false;
}
void justdoit() {
    string s;
    cin >> s;
    vector<int> res;
    for (int i = 1; i <= s.size(); i++) {
        if (judge(s, i)) {
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        if (i) cout << ' ';
        cout << res[i];
    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    justdoit();
    return 0;
}