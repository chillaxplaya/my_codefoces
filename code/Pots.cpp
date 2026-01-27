#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n) \
    cerr << "[" << #a << "] = {"; \
    for (int i = 0; i < (n); i++) cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";


#define all(x) (x).begin(), (x).end()
#define ll long long
struct node{
    int a, b;
    int pre;
    int step;
    int op;
    node(int a1, int b1, int step1,int pre1, int op1) : a(a1), b(b1), step(step1), pre(pre1), op(op1) {}
};
string op[] = {"FILL(1)", "FILL(2)", "DROP(1)", "DROP(2)", "POUR(1,2)", "POUR(2,1)"};
void dfsprint(vector<node> &path, int i) {
    if (path[i].pre == -1) {
        return;
    }
    dfsprint(path, path[i].pre);
    cout << op[path[i].op] << "\n";
}
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    set<pair<int, int>> vis;
    vector<node> path;
    vis.insert({0, 0});
    path.push_back(node(0, 0, 0, -1, 0));
    int ans = -1;
    for (int i = 0; i < path.size() ; i++) {
        node now = path[i];
        if (now.a == c || now.b == c) {
            ans = i;
            break;
        }
        for (int j = 0; j < 6; j++) {
            int ta, tb;
            if (j == 0) {
                ta = a;
                tb = now.b;
            } else if (j == 1) {
                ta = now.a;
                tb = b;
            } else if (j == 2) {
                ta = 0;
                tb = now.b;
            } else if (j == 3) {
                ta = now.a;
                tb = 0;
            } else if (j == 4) {
                if (now.a + now.b > b) {
                    ta = now.a + now.b - b;
                    tb = b;
                } else {
                    ta = 0;
                    tb = now.a + now.b;
                }
            } else if (j == 5) {
                if (now.a + now.b > a) {
                    ta = a;
                    tb = now.a + now.b - a;
                } else {
                    ta = now.a + now.b;
                    tb = 0;
                }
            }
            if (!vis.count({ta, tb})) {
                vis.insert({ta, tb});
                path.push_back(node(ta, tb, path[i].step + 1, i, j));
            }
        }
    }
    for (int i = 0; i < path.size(); i++) {
        cerr << i << " " << path[i].a << " " << path[i].b << " " << op[path[i].op] << " " << path[i].step << "\n";
    }
    debug(ans);
    if (ans == -1) {
        cout << "impossible\n";
    } else {
        cout << path[ans].step << "\n";
        dfsprint(path, ans);
    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}