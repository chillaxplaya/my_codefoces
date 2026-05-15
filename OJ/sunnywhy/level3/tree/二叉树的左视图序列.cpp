/*
二叉树的左视图序列
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-16 11:54:22
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
void justdoit() {
    int n;
    int l, r;
    cin >> n;
    rep(i, n) {
        cin >> l >> r;
        Tree[i].l = l;
        Tree[i].r = r;
    }
    queue<int> qu;
    qu.push(0);
    bool nullnode = false;
    int qsize = qu.size();
    vector<int> res;
    while (!qu.empty()) {
        qsize = qu.size();
        for (int i = 0; i < qsize; i++) {
            int getnode = qu.front();
            qu.pop();
            if (i == 0) {
                res.push_back(getnode);
            }
            if (Tree[getnode].l != -1)
                qu.push(Tree[getnode].l);
            if (Tree[getnode].r != -1)
                qu.push(Tree[getnode].r);
        }
    }
    for (int i = 0; i < res.size(); i++) {
        if (i) cout << ' ';
        cout << res[i];
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