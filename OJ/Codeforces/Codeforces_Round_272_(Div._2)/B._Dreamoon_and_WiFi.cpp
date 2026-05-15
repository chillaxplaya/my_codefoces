/*
B. Dreamoon and WiFi
Time Limit: 1000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/476/B
*/
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n)                 \
    cerr << "[" << #a << "] = {";       \
    for (int i = 0; i < (n); i++)       \
        cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
int count(int n, int k) {
    if (k == 0 || n == k) return 1;
    if (k == 1) {
        return n;
    }
    
    int cnt = 1;
    for (int i = n; i > n - k; i--) {
        cnt *= i;
    }
    for (int i = 2; i <= k; i++) {
        cnt /= i;
    }
    return cnt;
}
double n12(int x) {
    double cnt = 1;
    for (int i = 0; i < x; i++) {
        cnt /= 2;
    }
    return cnt;
}
void justdoit() {
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int cnt1 = 0, cnt0 = 0;
    for (auto &e : a) {
        if (e == '+') {
            cnt1++;
        }
    }
    cnt0 = n - cnt1;
    int res = 0;
    for (auto &e : b) {
        if (e == '+') {
            cnt1--;
        }
        if (e == '-') {
            cnt0--;
        }
        if (e == '?') {
            res++;
        }
    }
    if (cnt0 < 0 || cnt1 < 0) {
        cout << "0.000000000000\n";
        return;
    }
    debug(n12(cnt0 + cnt1));
    debug(count(cnt0 + cnt1, cnt0));
    cout << fixed << setprecision(12) << n12(cnt0 + cnt1) * count(cnt0 + cnt1, cnt0) << '\n';
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