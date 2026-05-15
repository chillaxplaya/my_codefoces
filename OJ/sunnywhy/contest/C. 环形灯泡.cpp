/*
C. 环形灯泡
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-13 19:44:38
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
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (a.find('1') == string::npos) {
        cout << "NO" << endl;
        return;
    }
    if (a.find('0') == string::npos) {
        cout << "NO" << endl;
        return;
    }
    if (b.find('0') == string::npos) {
        cout << "YES" << endl;
    }
    if (b.find('1') == string::npos) {
        cout << "YES" << endl;
    }
    cout << "NO";
    int flag = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        if (b[i] == '0') {

        } else {

        }
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