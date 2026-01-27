#include <bits/stdc++.h>
#include <cstddef>
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
char a[10005], b[10005];
void solve() {
    while (scanf("%s", a) != EOF) {
        scanf("%s", b);
        vector<int> asum(27), bsum(27);
        for (int i = 0; a[i] != '\0'; i++) {
            asum[a[i] - 'A']++;
        }
        for (int i = 0; a[i] != '\0'; i++) {
            bsum[b[i] - 'A']++;
        }
        sort(all(asum));
        sort(all(bsum));
        bool ok = true;
        for (int i = 0; i < 27; i++) {
            if (asum[i] != bsum[i]) {
                puts("NO");
                ok = false;
                break;
            }
        }
        if (ok) {
            puts("YES");
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