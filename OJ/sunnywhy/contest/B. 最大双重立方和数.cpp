/*
B. 最大双重立方和数
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-14 13:39:25
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
int sq[200005];
void justdoit() {
    int n;
    cin >> n;
    for (int i = 1; i <= 100; i++) {
        for (int j = i + 1; j <= 100; j++) {
            int t = i * i * i + j * j * j;
            if (t <= 200000) {
                sq[t]++;
            }
        }
    }
    for (int i = n; i >= 2; i--) {
        if (sq[i] >= 2) {
            cout << i << endl;
            return;
        }
    }
    cout << "none";
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