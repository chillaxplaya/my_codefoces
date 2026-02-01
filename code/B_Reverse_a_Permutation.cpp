#include <bits/stdc++.h>
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    int maxi;
    int maxn = n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = n - i;
    }
    int l = 0;
    while (a[l] == b[l] && l < n - 1) l++;
    debug(l);
    for (int i = 0; i < n; i++) {
        if (a[i] == (n - l)) maxi = i;
    }
    for (int i = 0; i < l; i++) {
        cout << a[i] << " ";
    }
    for (int i = maxi; i >= l; i--) {
        cout << a[i] << " ";
    }
    for (int i = maxi + 1; i < n; i++) {
        cout << a[i] << ' ';
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