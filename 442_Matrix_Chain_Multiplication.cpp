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
struct mtx{
    int r, c;
    mtx(int _r, int _c) : r(_r), c(_c) {}
    mtx() : r(-1), c(-1) {}
    bool operator==(const mtx &x) {
        return (r == x.r && c == x.c);
    }
    bool operator==(const int &x) {
        return (r == x && c == x);
    }
    mtx operator*(const mtx &x) {
        if(c == x.r) return mtx(r, x.c);
        return mtx(-1, -1);
    }
};
map<char, mtx> mtxs;
void solve() {
    int n, rt, ct;
    char c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c >> rt >> ct;
        mtxs[c] = mtx(rt, ct);
    }
    string exp;
    bool err = false;
    cin.get();
    while (getline(cin, exp)) {
        err = false;
        debug(exp);
        int res = 0;
        stack <mtx> st;
        for (auto e : exp) {
            if (e == '(') {
                continue;
            } else if(e == ')') {
                mtx A = st.top();
                st.pop();
                mtx B = st.top();
                st.pop();
                mtx C = B * A;
                if (C == -1) {
                    cout << "error\n";
                    err = true;
                    break;
                } else {
                    res += (B.r * B.c * A.c);
                    st.push(C);
                }
            } else {
                st.push(mtxs[e]);
            }
        }
        if (!err) {
            cout << res << "\n";
        }
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