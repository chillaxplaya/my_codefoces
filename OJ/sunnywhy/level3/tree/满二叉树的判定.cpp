/*
满二叉树的判定
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-15 12:07:51
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
    int l, r;
    Treenode() : l(-1), r(-1) {}
}Tree[1024];
int getHeight(int x);
bool isFull(int x) {
    if (x == -1) return true;
    if (getHeight(Tree[x].l) != getHeight(Tree[x].r)) {
        return false;
    }
    return isFull(Tree[x].l) && isFull(Tree[x].r);
}
int getHeight(int x) {
    if (x == -1) return 0;
    int lh = getHeight(Tree[x].l);
    int rh = getHeight(Tree[x].r);
    return max(lh, rh) + 1;
}
void justdoit() {
    int n;
    int l, r;
    cin >> n;
    rep(i, n) {
        cin >> l >> r;
        Tree[i].l = l;
        Tree[i].r = r;
    }
    cout << (isFull(0) ? "Yes" : "No");
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