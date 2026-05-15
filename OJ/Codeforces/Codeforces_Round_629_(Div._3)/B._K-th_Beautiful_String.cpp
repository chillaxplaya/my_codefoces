/*
B. K-th Beautiful String
Time Limit: 1000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/1328/B
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
    ll n, k;
    cin >> n >> k;
    ll l = 1, r = 2000005;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (mid * (mid + 1) / 2 < k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    int idx1 = l, idx2 = l * (l + 1) / 2 - k;

    string ans(l + 1, 'a');
    ans[0] = 'b';
    ans[idx2 + 1] = 'b';
    string t(n - ans.size(), 'a');
    cout << t + ans << "\n";
}
void test() {
    string x(18, 'a');
    x += "bb";
    do {
        cout << x << " " << 20 - x.find_first_of('b') - 1 << endl;
    } while(next_permutation(all(x)));
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    // test();
    while (T--)
        justdoit();
    return 0;
}