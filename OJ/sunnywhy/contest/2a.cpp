/*
${title}
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
*/
#include <bits/stdc++.h>
#include <vector>
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
double eps = 1E-12;
bool checkD(const long double &a, const long double &b) {
    return fabsl(a - b) <= eps;
}
void justdoit() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    for (auto &e : a) {
        cin >> e;
    }
    for (auto &e : b) {
        cin >> e;
    }

    set<ll> res;
    set<pair<ll,ll>> ks;
    set<long double> kres;
    for (int i = 0; i < m - n + 1; i++) {
        long double k = 0;
        for (int j = 1; j < n; j++) {
            if (j == 1) {
                k = (long double)(b[i + 1] - b[i]) / (a[1] - a[0]);
                if (n == 2) {
                    ll g = std::gcd((b[i + 1] - b[i]), (a[1] - a[0]));
                    ks.insert({(b[i + 1] - b[i]) / g, (a[1] - a[0]) / g});
                    res.insert(b[i + 1] - b[i]);
                }
                continue;
            }
            if ((__int128)(a[1] - a[0]) * (b[i + j] - b[i]) != (__int128)(b[i + 1] - b[i]) * (a[j] - a[0])) {
                break;
            }
            if (j == n - 1) {
                ll g = std::gcd((b[i + 1] - b[i]), (a[1] - a[0]));
                ks.insert({(b[i + 1] - b[i]) / g, (a[1] - a[0]) / g});
                res.insert(b[i + 1] - b[i]);
            }
        }
    }
    cout << ks.size() << endl;
    // for (int i = 0 ; i < res.size(); i++) {
    //     if (i) cout << " ";
    //     cout << res[i];
    // }
    bool first = true;
    for (auto &e : res) {
        if (!first) cout << " ";
        cout << e;
        first = false;
    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    justdoit();
    return 0;
}