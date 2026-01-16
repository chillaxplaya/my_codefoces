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
    int n, l;
    cin >> n >> l;
    vector<string> s(n);
    for (int i = 0; i < n;i++) {
        cin >> s[i];
    }
    string ans = "";
    int hamans = 0;
    for (int i = 0; i < l;i++) {
        int a = 0, c = 0, g = 0, t = 0;
        for(int j = 0; j < n; j++) {
            if (s[j][i] == 'A') a++;
            else if (s[j][i] == 'C') c++;
            else if (s[j][i] == 'G') g++;
            else if (s[j][i] == 'T') t++;
        }
        debug(a, c, g, t);
        int acgt = max(a, max(c, max(g, t)));
        if (a == acgt) ans += 'A';
        else if (c == acgt) ans += 'C';
        else if (g == acgt) ans += 'G';
        else if (t == acgt) ans += 'T';
        hamans += (n - acgt);
    }
    cout << ans << endl << hamans << endl;
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