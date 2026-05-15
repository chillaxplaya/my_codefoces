/*
填充二叉查找树
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-16 11:59:14
user: playa
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
#define endl '\n'
typedef pair<int, int> pi;
struct Treenode {
    int val;
    int l, r;
    Treenode() : l(-1), r(-1) {}
}Tree[1024];
vector<int> a;
int idx = 0;
void inorder(int x) {
    if (x == -1) return;
    inorder(Tree[x].l);
    Tree[x].val = a[idx++];
    debug(x, Tree[x].val);
    inorder(Tree[x].r);
}
bool first = true;
void preorder(int x) {
    if (x == -1) return;
    if (!first) cout << " ";
    cout << Tree[x].val;
    first = false;
    preorder(Tree[x].l);
    preorder(Tree[x].r);
}
void justdoit() {
    int n;
    int l, r;
    cin >> n;
    a.resize(n);
    for (auto &e : a) cin >> e;
    sort(all(a));
    rep(i, n) {
        cin >> l >> r;
        Tree[i].l = l;
        Tree[i].r = r;
    }
    inorder(0);
    preorder(0);
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