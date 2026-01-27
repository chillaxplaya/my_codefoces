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
vector<int> a(200005);
int getDigit(int x) {
    int t = x;
    while (t) {
        x += (t%10);
        t /= 10;
    }
    return x;
}
void initDigit() {
    for (int i = 1; i <= 100000; i++) {
        int t = getDigit(i);
        if(!a[t])
            a[t] = i;
    }
}
void solve() {
    int x;
    cin >> x;
    cout << a[x] << endl;
}
int main() {
    // srand(time(0));
    initDigit();
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}