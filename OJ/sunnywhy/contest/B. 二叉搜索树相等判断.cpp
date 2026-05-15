/*
B. 二叉搜索树相等判断
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-12 19:40:03
user: playa
*/
#include <bits/stdc++.h>
#include <cstddef>
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
struct node{
    node *left, *right;
    int val;
    node() : val(-1), left(nullptr), right(nullptr) {}
    node(int _val) : val(_val), left(nullptr), right(nullptr) {}
};
vector<int> res;
void preorder(node *nd) {
    if (nd == nullptr) return;
    res.push_back(nd->val);
    preorder(nd->left);
    preorder(nd->right);
}
void justdoit() {
    int n, x;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;
    node *head = nullptr;
    node *t;
    rep(i, n) {
        cin >> x;
        if (head == nullptr) {
            head = new node(x);
        } else {
            t = head;
            while(1) {
                if (x > t->val) {
                    if (t->right == nullptr) {
                        t->right = new node(x);
                        break;
                    } else {
                        t = t->right;
                    }
                } else {
                    if (t->left == nullptr) {
                        t->left = new node(x);
                        break;
                    } else {
                        t = t->left;
                    }
                }
            }
        }
    }
    preorder(head);
    debug(res);
    if (res == a) {
        cout << "Yes";
    } else {
        cout << "No";
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