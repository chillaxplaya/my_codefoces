#include <bits/stdc++.h>
#include <utility>
#include <vector>
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
int towFind(vector<int> &a, int n, int x) {
    int l = 0;
    int r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] > x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
void solve() {
    int n;
    cin >> n;
    vector<int> sword(n);
    vector<int> stage(n);
    for (int i = 0; i < n; i++) {
        cin >> sword[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> stage[i];
    }
    for (int i = 1; i < n; i++) {
        stage[i] += stage[i - 1];
    }
    //000000000
    //0000000000
    //000000000
    debug(stage);
    sort(all(sword));
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = towFind(stage, n, n - i);
        debug(l);
        if (l > 0 && stage[l - 1] <= n - i) {
            
            ans = max(ans, (ll)(l) * sword[i]);
            debug(ans);
        } 
    }
    cout << ans << "\n";
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