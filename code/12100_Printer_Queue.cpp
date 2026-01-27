#include <bits/stdc++.h>

#include <vector>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n)                                           \
    cerr << "[" << #a << "] = {";                                 \
    for (int i = 0; i < (n); i++) cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

struct work {
    int prior;
    int idx;
    work(int p, int i) : prior(p), idx(i) {}
    bool operator<(const work& ot) { return prior < ot.prior; }
};
#define all(x) (x).begin(), (x).end()
#define ll long long
int cmp(int a, int b) { return a > b; }
void solve() {
    int n, idx;
    cin >> n >> idx;
    vector<int> a(n);
    queue<work> qu;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        qu.push(work(a[i], i));
    }
    sort(all(a), cmp);
    int index = 0;
    int ans = 1;
    while (true) {
        if (!qu.empty()) {
            if (qu.front().prior < a[index]) {
                qu.push(qu.front());
                qu.pop();
            } else {
                if (qu.front().idx == idx) {
                    cout << ans << "\n";
                    break;
                } else {
                    qu.pop();
                    index++;
                    ans++;
                }
            }
        }
    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}