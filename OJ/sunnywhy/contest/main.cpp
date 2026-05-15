/*
${title}
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
*/
#include <bits/stdc++.h>
#include <cmath>
#include <sys/types.h>
#include <vector>
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
    int id;
    Node *left, *right;
    Node() {}
    Node(int _id, Node *_left, Node *_right) : id(_id), left(_left), right(_right) {}
};
double eps = 1E-12;
bool first = true;
void justdoit() {
    
}
int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        justdoit();
    return 0;
}