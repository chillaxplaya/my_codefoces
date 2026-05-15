/*
二叉树的高度
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-04 11:52:50
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
struct node {
    int l, r;
}tree[10005];
int n;
int l, r;
int getHigh(int root) {
    if (root == -1) {
        return 0;
    }
    return max(getHigh(tree[root].l), getHigh(tree[root].r)) + 1;
}
void justdoit() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tree[i].l >> tree[i].r;
    }
    cout << getHigh(0);
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