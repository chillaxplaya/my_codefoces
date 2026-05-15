/*
集合求交II
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-03 10:30:18
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (auto &e : a) {
        cin >> e;
    }
    for (auto &e : b) {
        cin >> e;
    }
    int i = 0, j = 0;
    bool blank = false;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            if (blank) cout << " ";
            cout << b[j];
            blank = true;
            i++;
            j++;
        } else if (a[i] < b[j]) {
            if (blank) cout << " ";
            cout << a[i];
            blank = true;
            i++;
        } else if (a[i] > b[j]) {
            if (blank) cout << " ";
            cout << b[j];
            blank = true;
            j++;
        }
    }
    while (i < n) {
        if (blank) cout << " ";
        cout << a[i];
        blank = true;
        i++;
    }
    while (j < m) {
        if (blank) cout << " ";
        cout << b[j];
        blank = true;
        j++;
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