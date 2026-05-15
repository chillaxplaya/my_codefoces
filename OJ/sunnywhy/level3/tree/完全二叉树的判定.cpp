/*
完全二叉树的判定
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-15 12:43:18
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
    while (!qu.empty()) {
        int getnode = qu.front();
        qu.pop();
        if (getnode == -1) {
            nullnode = true;
            continue;
        } else if (nullnode) {
            cout << "No";
            return;
        }
        qu.push(Tree[getnode].l);
        qu.push(Tree[getnode].r);
    }
    cout << "Yes";
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