#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()
#define ll long long
int a[200005];
int b[200005];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (b[i] != a[i]) {
            if (a[i] % 2 != b[i] % 2) {
                flag = false;
            }
        }
    }
    if (flag) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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