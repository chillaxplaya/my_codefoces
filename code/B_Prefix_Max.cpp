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

void solve() {
    int n, mana = -0x3ffffff,maxi = -1;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] >= mana) {
            mana = a[i];
            maxi = i;
        }
    }
    debug(maxi);
    for (int i = 0; i < maxi; i++) {
        debug(a[i],a[maxi]);
        if(a[i] < a[maxi]) {
            
            swap(a[i],a[maxi]);
            break;
        }
    }
    mana = -0x3ffffff;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > mana) { mana = a[i]; }
        sum += mana;
    }
    debug(a, maxi);
    cout << sum << '\n';
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