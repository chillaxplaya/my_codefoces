#include <bits/stdc++.h>
#include <vector>
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
typedef pair<int, int> pi;
void justdoit() {
    int n;
    cin >> n;
    vector<pi> kt(n);
    for (auto &[a, b] : kt) {
        cin >> a >> b;
    }
    sort(all(kt),[&](auto &a, auto &b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });
    debug(kt);
    vector<int> res;
    res.reserve(n);
    for (auto &[_, b] : kt) {
        if (res.empty() || b > res.back()) {
            res.push_back(b);
        } else {
            auto i = lower_bound(all(res), b) - res.begin();
            if (i == res.size()) {
                res.push_back(b);
            } else {
                res[i] = b;
            }
        }
    }
    cout << res.size();
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