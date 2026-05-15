/*
D. 还原垂直投影
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-04 20:15:00
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
}tree[2005];
int build(vector<int> porder, vector<int> morder) {
    debug(porder, morder);
    if (porder.size() == 0) return -1;

    int rootp = porder.back();
    int rooti = 0;
    debug(rootp);
    for (int i = 0; i < morder.size(); i++) {
        if (morder[i] == rootp) {
            rooti = i;
            break;
        }
    }
    tree[rootp].l = build(vector<int>(porder.begin(), porder.begin() + rooti), vector<int>(morder.begin(), morder.begin() + rooti));
    tree[rootp].r = build(vector<int>(porder.begin() + rooti, porder.end() - 1), vector<int>(morder.begin() + rooti + 1, morder.end()));
    debug(tree[rootp].l, tree[rootp].r);
    return rootp;
}
void justdoit() {
    int n;
    cin >> n;
    vector<int> porder(n);
    vector<int> morder(n);
    for (auto &e : porder) {
        cin >> e;
    }
    for (auto &e : morder) {
        cin >> e;
    }
    int root = build(porder, morder);
    debug(root);

    vector<int> can(5000, -1);
    vector<int> prop(5000, -1);
    int pianyi = 2500;
    queue<int> qu;
    qu.push(root);
    can[2500] = root;
    prop[root] = 2500;
    while (!qu.empty()) {
        int cur = qu.front();
        qu.pop();
        debug(cur);
        debug(tree[cur].l, tree[cur].r);
        if (tree[cur].l != -1) {
            prop[tree[cur].l] = prop[cur] - 1;
            if (can[prop[tree[cur].l]] == -1) {
                can[prop[tree[cur].l]] = tree[cur].l;
            }
            qu.push(tree[cur].l);
        }
        if (tree[cur].r != -1) {
            prop[tree[cur].r] = prop[cur] + 1;
            if (can[prop[tree[cur].r]] == -1) {
                can[prop[tree[cur].r]] = tree[cur].r;
            }
            qu.push(tree[cur].r);
        }
    }
    debug(vector<int>(can.begin()+2495, can.begin()+2520));
    bool first = true;
    for (auto &e : can) {
        
        if (e != -1) {
            if (!first) cout << " ";
            cout << e;
            first = false;
        }
        
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