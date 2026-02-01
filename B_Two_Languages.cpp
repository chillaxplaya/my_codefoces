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
    int n, m;
    cin >> n >> m;
    string s1, s2, s;
    cin >> s1 >> s2;
    int q;
    cin >> q;
    while (q--) {
        cin >> s;
        bool tak = true;
        bool aoki = true;
        for (auto& e : s) {
            if (s1.find(e) == string::npos) {
                tak = false;
            }
            if (s2.find(e) == string::npos) {
                aoki = false;
            }
        }
        debug(tak, aoki);
        if ((tak ^ aoki) == 0) {
            cout << "Unknown\n";
        } else if (tak) {
            cout << "Takahashi\n";
        } else {
            cout << "Aoki\n";
        }
    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}