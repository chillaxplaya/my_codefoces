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
int lowerfind(vector<int> &a, int x) {
    int l = 0;
    int r = a.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if(a[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
void solve() {
    int n, m;
    int cas = 1;
    while (cin >> n >> m && n) {
        //CASE# 1:
        cout << "CASE# " << cas++ << ":\n";
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(all(a));
        for (int i = 0; i < m; i++) {
            int q;
            cin >> q;
            int t = lowerfind(a, q);
            if(a[t] == q) {
                cout << q << " found at " << t + 1 << "\n";
            } else {
                cout << q << " not found\n" ;
            }
            
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