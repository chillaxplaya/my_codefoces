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
    while (cin >> n && n) {
        
        debug(n);
        vector<int> a(n);
        while (cin >> a[n - 1] && a[n - 1]) {
            
            for (int i = n - 2; i >= 0; i--) {
                cin >> a[i];
            }
            debug(a);
            stack<int> st;
            for (int i = 1; i <= n; i++) {
                st.push(i);
                while (!st.empty() && !a.empty() && st.top() == a.back()) {
                    st.pop();
                    a.pop_back();
                }
            }
            if (!st.empty()) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
            a.resize(n);
        }
        cout << "\n";
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