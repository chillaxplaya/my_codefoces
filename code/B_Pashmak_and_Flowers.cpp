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
#define rep(i,n) for (int i = 0; i < n; i++)

void justdoit() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) {
        cin >> e;
    }
    sort(all(a));
    cout << a[n - 1] - a[0] << " ";
    if (a[n - 1] - a[0] == 0) {
        cout << 1LL * (n - 1) * n /2;
        return;
    }
    ll lcnt = 1;
    int l = 0, r = n - 1;
    while (l < r && a[l + 1] == a[l]) {
        lcnt++;
        l++;
    }
    ll rcnt = 1;
    while (l < r && a[r - 1] == a[r]) {
        rcnt++;
        r--;
    }
    if (l == r) lcnt--;
    cout << lcnt * rcnt;
    
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) justdoit();
    return 0;
}