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
const int L = 1;
const int R = 2;
int a[10005];
int getNext(int i, int k, int n, int D) {
    while (k) {
        if ( a[i] ) {
            k--;
            if (!k) return i;
        }
        if (D == R) {
            i++;
        } else {
            i--;
        }
        if (i < 0) {
            i += n;
        }
        i %= n;
    }
}
void solve() {
    int n, k, m;
    while (cin >> n >> k >> m && n) {
        debug(n, k, m);
        for(int i = 0; i < n; i++) {
            a[i] = 1;
        }
        int i = 0;
        int j = n - 1;
        int left = n;
        while (left > 0) {
            i = getNext(i, k, n, R);
            j = getNext(j, m, n, L);
            debug(left);
            if (i != j) {
                a[i] = a[j] = 0;
                left -= 2;
                // cout << "  " << i + 1 << "  " << j + 1; 
                printf("%3d%3d", i + 1, j + 1);
            } else {
                a[i] = 0;
                left -= 1;
                // cout << "  " << i + 1;
                printf("%3d", i + 1);
            }
            if (left) {
                cout << ',';
            }
        }
        cout << endl;
    }
}
int main() {
    // srand(time(0));
    // ios::sync_with_stdio(0);
    // cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}