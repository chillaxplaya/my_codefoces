/*
方程求根
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-08 13:28:37
*/
#include <bits/stdc++.h>
#include <ios>
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
#define eps 1E-10
double a;
double bsearch(double l, double r) {
    while (r - l > eps) {
        double mid = (r + l) / 2;
        if (mid * mid * mid +mid * mid + mid > a) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return l;
}
void justdoit() {
    cin >> a;
    cout << fixed << setprecision(2) << bsearch(-200, 200);
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