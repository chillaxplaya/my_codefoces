/*
D. 二叉树序列转换
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-14 14:01:52
user: playa
*/
#include <bits/stdc++.h>
#include <cstdio>
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
struct node {
    int val;
    int l, r;
    node() : val(-1), l(-1), r(-1) {}
    node(int _val) : val(_val), l(-1), r(-1) {}
}Tree[30005];
int idx = 0;
int build() {
    char c = getchar();
    int getidx = idx++;
    if (c >= '0' && c <= '9') {
        Tree[getidx].val = (c - '0');
        Tree[getidx].l = build();
        Tree[getidx].r = build();
        return getidx;
    } else if (c == '#') {
        return -1;
    }
    return -1;
}
vector<int> preres;
vector<int> cres;
void preo(int x) {
    if (x == -1) {
        return;
    }
    
    preo(Tree[x].l);
    preres.push_back(Tree[x].val);
    preo(Tree[x].r);
}
int ans = 0;
void postreo(int x) {
    if (x == -1) {
        return;
    }
    ans++;
    postreo(Tree[x].r);
    
}

void justdoit() {
    build();
    preo(0);
    queue<int> qu;
    qu.push(0);
    while (!qu.empty()) {
        int x = qu.front();
        qu.pop();
        cres.push_back(Tree[x].val);
        if (Tree[x].l != -1) {
            qu.push(Tree[x].l);
        }
        if (Tree[x].r != -1) {
            qu.push(Tree[x].r);
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