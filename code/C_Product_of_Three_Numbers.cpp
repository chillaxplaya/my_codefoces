#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n)                 \
    cerr << "[" << #a << "] = {";       \
    for (int i = 0; i < (n); i++)       \
        cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

void justdoit() {
    int n;
    cin >> n;
    int q = sqrt(n);
    for (int i = 2; i <= q; i++) {
        if (n % i == 0) {
            int nn = n / i;
            for (int j = i + 1; j <= q; j++) {
                if (nn % j == 0 && nn / j != j && nn / j != i && nn / j > 1) {
                    cout << "YES\n";
                    cout << i << " " << j << " " << n / i / j << "\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
    return;
}
int main() {
    // srand(time(0));
    // ios::sync_with_stdio(0);
    // cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        justdoit();
    return 0;
}