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

//a <= b 
//a - min(k % b, a);
// a > b
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
    int a, b, k;
    int t = k / b;
    int ans;
    cin >> a >> b >> k;
    if (b >= a) {
        cout << a - min(k % b, a);
    } else {
        int t = k / b;
        if((t & 1) == 0) {
            cout << a -  (k % b);
        } else {
            cout << b - (k % b); 
        }
    }
    cout << endl;
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