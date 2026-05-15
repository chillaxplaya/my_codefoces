/*
${title}
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

void justdoit() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int l = 0, r = 0;
    ll sum = 0, ans = -1;
    int ansl = 0, ansr = n - 1;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        r = i;
        if (sum > ans) {
            ans = sum;
            ansl = l;
            ansr = r;
        }
        if (sum < 0) {
            l = i + 1;
            sum = 0;
        }
    }
    if (ans == -1) ans = 0;
    cout << ans << " " << a[ansl] << " " << a[ansr];
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    justdoit();
    return 0;
}