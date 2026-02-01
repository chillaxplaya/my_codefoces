#include <bits/stdc++.h>
#include <algorithm>
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
struct Point {
    int x, y; 
    int idx;
};
int cross(const Point& a, const Point& b) {
    return (a.x * b.y - a.y * b.x);
}
bool cmp(const Point& a, const Point& b) {
    int ah = (a.y > 0) ? 0 : ((a.y == 0 && a.x > 0) ? 0 : 1);
    int bh = (b.y > 0) ? 0 : ((b.y == 0 && b.x > 0) ? 0 : 1);
    if (ah != bh) return ah < bh;
    return cross(a, b) > 0;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].idx = i;
    }
    sort(p.begin(), p.end(), cmp);
    reverse(p.begin(), p.end());
    // for (auto e : p) {
    //     cerr << e.x << " " << e.y << "\n";
    // }
    vector<int> rev(n);
    for (int i = 0; i < n; i++) {
        rev[p[i].idx] = i;
    }
    vector<int> l(n), r(n);
    l[0] = 0, r[n - 1] = n - 1;
    for (int i = 1; i < n; i++) {
        l[i] = (cmp(p[i], p[i - 1]) ? i : l[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        r[i] = (cmp(p[i + 1], p[i]) ? i : r[i + 1]);
    }
    int idx1, idx2;
    for (int i = 0; i < q; i++) {
        cin >> idx1 >> idx2;
        --idx1;
        --idx2;
        int a = l[rev[idx1]];
        int b = r[rev[idx2]];
        if (b >= a) {
            cout << b - a + 1 << "\n";
        } else {
            cout << n - a + b + 1 << "\n";
        }
    }
}

int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    solve();
    return 0;
}