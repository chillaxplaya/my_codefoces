/*
链表去除重复元素
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-11 15:01:57
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
struct Node {
    int val;
    int next;
    Node() : val(0), next(-1) {}
}List[2005];
int vis[300005];
void justdoit() {
    int n, head;
    cin >> n >> head;
    int node, val, nextnode;
    rep(i, n) {
        cin >> node >> val >> nextnode;
        List[node].val  = val;
        List[node].next = nextnode;
    }
    int last = head;
    node = List[last].next;
    vis[List[head].val] = 1;
    while (node != -1) {
        if (vis[List[node].val]) {
            List[last].next = List[node].next;
        } else {
            vis[List[node].val] = 1;
            last = node;
        }
        
        node = List[node].next;
    }
    node = head;
    while (node != -1) {
        cout << node << " " << List[node].val << " " << List[node].next << endl;
        node = List[node].next;
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