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

#define eps 1E-12
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

typedef pair<int, double> pi;
void justdoit() {
    vector<double> a(1005, 0);
    vector<double> b(1005, 0);
    int k;
    int c;
    double d;
    cin >> k;
    rep(i, k) {
        cin >> c >> d;
        a[c] += d;
    }
    cin >> k;
    rep(i, k) {
        cin >> c >> d;
        b[c] += d;
    }
    for (int i = 0; i <= 1004; i++) {
        a[i] += b[i];
    }
    vector<pi> res;
    rep(i, 1004) {
        if (a[i] > 1e-9)
            res.push_back({i, a[i]});
    }
    reverse(all(res));
    cout << res.size();
    for (int i = 0; i < res.size(); i++) {
        cout << " "  << res[i].first << " " << fixed << setprecision(1) << res[i].second;
        // printf("%d %.1lf", res[i].first, res[i].second);
    }
}
int main() {
    // srand(time(0));
    // ios::sync_with_stdio(0);
    // cout.tie(0), cin.tie(0);
    justdoit();
    return 0;
}