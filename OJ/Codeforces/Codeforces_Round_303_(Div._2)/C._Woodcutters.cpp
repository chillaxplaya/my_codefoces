/*
C. Woodcutters
Time Limit: 1000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/545/C
*/
#include <bits/stdc++.h>
#include <vector>
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
typedef pair<int, int> pi;
void justdoit() {
    int n;
    cin >> n;
    if (n == 1 || n == 2) {
        cout << n;
        return;
    }
    vector<int> stay(n, 0);
    vector<int> left(n, -INF);
    vector<int> right(n, -INF);
    vector<pi> tree(n);
    for (auto &[a, b] : tree) {
        cin >> a >> b;
    }
    stay[0] = 0;
    left[0] = 1;
    right[0] = tree[0].first + tree[0].second < tree[1].first ? 1 : -INF;
    for (int i = 1; i < n - 1; i++) {
        stay[i] = max(max(stay[i - 1], left[i - 1]), right[i - 1]);
        if (tree[i - 1].first + tree[i - 1].second < tree[i].first - tree[i].second) {
            left[i] = max(left[i], right[i - 1] + 1);
        }
        if (tree[i - 1].first < tree[i].first - tree[i].second) {
            left[i] = max(max(left[i], left[i - 1] + 1), stay[i - 1] + 1);
        }
        if (tree[i].first + tree[i].second < tree[i + 1].first) {
            right[i] = max(max(stay[i - 1], left[i - 1]), right[i - 1]) + 1;
        }
    }
    cout << max(max(stay[n - 2], left[n - 2]), right[n - 2]) + 1;

}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        justdoit();
    return 0;
}