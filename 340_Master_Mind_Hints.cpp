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
    int n, x, _case = 1;
    while (cin >> n && n) {
        cout << "Game " << _case++ << ":" << endl;
        vector<int> a(n);
        vector<int> a_map(10);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a_map[a[i]]++;
        }
        while(1) {
            int A = 0, B = 0;
            vector<int> b_map(10);
            for (int i = 0; i < n; i++) {
                cin >> x;
                if(a[i] == x) A++;
                b_map[x]++;
            }
            for(int i = 1; i < 10; i++) {
                B += min(a_map[i], b_map[i]);
            }
            if(!x)
                break;
            cout << "    (" << A << "," << B - A  << ")" << endl;
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