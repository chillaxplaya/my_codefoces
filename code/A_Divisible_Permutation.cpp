#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n) \
    cerr << "[" << #a << "] = {"; \
    for (int i = 0; i < (n); i++) cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";


#define all(x) (x).begin(), (x).end()
#define ll long long
int use[105];
int per[105];
bool fd = false;
//2 99 1 100
//.    2 1 3
//        3 2 4 1 5
//           2 3 1 4
int dfs(int &n, int k) {
    if (fd) {
        return 1;
    }
    if (k == n) {
        fd = true;
        return 1;
    }
    if (k > n) {
        return - 1;
    }
    int ret1 = 0;
    int ret2 = 0;
    for (int i = k; i + per[k] <= n || per[k] - i >= 0; i += k) {
        int nxt = per[k] + k;
        if (nxt > 0 && nxt <= n && !use[nxt]) {
            per[k + 1] = nxt;
            use[nxt] = 1;
            ret1 = dfs(n, k + 1);
            if(fd) return 1;
            per[k + 1] = 0;
            use[nxt] = 0;
        }
        nxt = per[k] - k;
        if (nxt > 0 && nxt <= n && !use[nxt]) {
            per[k + 1] = nxt;
            use[nxt] = 1;
            ret2 = dfs(n, k + 1);
            if(fd) return 1;
            per[k + 1] = 0;
            use[nxt] = 0;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    int a = (n + 1) / 2;
    int minus = 1;
    if (n % 2) {
        minus = 0;
    }
    int i = 1;
    while (a > 0) {
        cout << a << " ";
        if ((minus = 1 - minus)) {
            a -= (i++);
        } else {
            a += (i++);
        }
    }
    cout << '\n';
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}