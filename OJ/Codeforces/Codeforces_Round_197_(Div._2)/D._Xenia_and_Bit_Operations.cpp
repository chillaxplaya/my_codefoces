/*
D. Xenia and Bit Operations
Time Limit: 2000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/339/D
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
struct node {
    int l, r;
    int val;
    node() : l(0), r(0), val(0) {}
};
ostream & operator<<(ostream &os, const node &t) {
    os << t.l << " " << t.r << " " <<t.val;
}
int build(vector<node> &tree, int l, int r, int idx) {
    if (l == r) {
        cin >> tree[idx].val;
        tree[idx].l = l;
        tree[idx].r = r;
        return 0;
    }
    int mid = l + (r - l) / 2;
    int op = build(tree, l, mid, idx * 2 + 1) & build(tree, mid + 1, r, idx * 2 + 2);
    tree[idx].val = (op == 0) ? (tree[idx * 2 + 1].val | tree[idx * 2 + 2].val) : (tree[idx * 2 + 1].val ^ tree[idx * 2 + 2].val);
    tree[idx].l = l;
    tree[idx].r = r;
    return 1 - op;
}
int modify(vector<node> &tree, int idx, int p, int b) {
    if (tree[idx].l == tree[idx].r && tree[idx].l == p) {
        tree[idx].val = b;
        return 0;
    }
    int mid = tree[idx].l + (tree[idx].r - tree[idx].l) / 2;
    int op;
    if (p <= mid) {
        op = modify(tree, idx * 2 + 1, p, b);
    } else {
        op = modify(tree, idx * 2 + 2, p, b);
    }
    tree[idx].val = (op == 0) ? (tree[idx * 2 + 1].val | tree[idx * 2 + 2].val) : (tree[idx * 2 + 1].val ^ tree[idx * 2 + 2].val);
    return 1 - op;
}
void justdoit() {
    int n, m;
    cin >> n >> m;
    vector<node> tree(1 << (n + 2));
    build(tree, 0, (1 << n) - 1, 0);
    int p, b;
    rep(i, m) {
        cin >> p >> b;
        modify(tree, 0, p - 1, b);
        cout << tree[0].val << "\n";
    }

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