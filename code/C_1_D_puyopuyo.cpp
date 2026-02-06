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

void justdoit() {
    int n, x;
    vector<int> a;
    cin >> n;
    a.reserve(n);
    rep(i, n) {
        cin >> x;
        if (a.size() < 3) {
            a.push_back(x);
        } else if (x == a[a.size() - 1] && x == a[a.size() - 2] && x == a[a.size() - 3]) {
            a.pop_back();
            a.pop_back();
            a.pop_back();
        } else {
            a.push_back(x);
        }
        debug(a);
    }
    cout << a.size();
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