/*
C - Insert and Erase A
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc447/tasks/abc447_c
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

void justdoit() {
    string a, b;
    cin >> a >> b;
    int al = a.size(), bl = b.size();
    int idxa = 0, idxb = 0;
    int res = 0;
    while(1) {
        if (idxa == al && idxb == bl) break;
        if (idxa < al && idxb < bl && a[idxa] == b[idxb]) {
            idxa++;
            idxb++;
        } else if ((idxa < al && a[idxa] == 'A')) {
            idxa++;
            res++;
        } else if ((idxb < bl && b[idxb] == 'A')) {
            idxb++;
            res++;
        } else {
            res = -1;
            break;
        }
    }
    cout << res << endl;
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