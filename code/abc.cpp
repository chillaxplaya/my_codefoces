#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n)                                                        \
    cerr << #a << " = [";                                                      \
    for (int i = 0; i < (n); i++) cerr << (a)[i] << (i + 1 < (n) ? ", " : ""); \
    cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
map<string, int> buff;
bool judgeall(string s, char c) {
    if (s.empty()) { return true; }
    for (auto e : s) {
        if (e != c) { return false; }
    }
    return true;
}
int dfs(string a, string b, string c, int k) {
    string t = a + "," + b + "," + c;
    debug(t, a, b, c, k);
    if (k >= 18) return -1;
    if (judgeall(a, 'A') && judgeall(b, 'B') && judgeall(c, 'C')) { return k; }
    if (buff.count(t)) {
        if (k >= buff[t])
            return -1;
        else
            buff[t] = k;
    } else {
        buff[t] = k;
    }
    int res = 0x3fffff;
    string at, bt, ct;
    if (a.size() > 0) {
        at = a;
        at.pop_back();
        bt = b + a[a.size() - 1];
        int aa1 = dfs(at, bt, c, k + 1);
        if (aa1 != -1) { res = min(aa1, res); }
        ct = c + a[a.size() - 1];
        int aa2 = dfs(at, b, ct, k + 1);
        if (aa2 != -1) { res = min(aa2, res); }
    }

    if (b.size() > 0) {
        bt = b;
        bt.pop_back();

        ct = c;
        at = a + b[b.size() - 1];
        int aa1 = dfs(at, bt, c, k + 1);
        if (aa1 != -1) { res = min(aa1, res); }
        ct = c + b[b.size() - 1];
        int aa2 = dfs(a, bt, ct, k + 1);
        if (aa2 != -1) { res = min(aa2, res); }
    }

    if (c.size() > 0) {
        ct = c;
        ct.pop_back();

        at = a + c[c.size() - 1];
        int aa1 = dfs(at, b, ct, k + 1);
        if (aa1 != -1) { res = min(aa1, res); }
        bt = b + c[c.size() - 1];
        int aa2 = dfs(a, bt, ct, k + 1);
        if (aa2 != -1) { res = min(aa2, res); }
    }
    return res;
}
struct node {
    string s;
    int k;
    node(string ss, int kk) : s(ss), k(kk) {}
};
void getabc(string &a, string &b, string &c, string s) {
    a.clear();
    b.clear();
    c.clear();
    int i = 0;
    for (i = 0; s[i] != ','; i++) { a += s[i]; }
    i++;
    for (; s[i] != ','; i++) { b += s[i]; }
    i++;
    for (; i < s.size(); i++) { c += s[i]; }
}
void solve() {
    string as, bs, cs;
    getline(cin, as);
    getline(cin, bs);
    getline(cin, cs);
    string t = as + "," + bs + "," + cs;
    cout << dfs(as, bs, cs, 0);
    return ;
    queue<node> qu;
    node a(t, 0);
    qu.push(a);
    while (!qu.empty()) {
        node t = qu.front();
        qu.pop();
        string a, b, c;
        getabc(a, b, c, t.s);
        if (judgeall(a, 'A') && judgeall(b, 'B') && judgeall(c, 'C')) {
            cout << t.k << "\n";
            return;
        }
        string at, bt, ct;
        if (a.size() > 0) {
            at = a;
            at.pop_back();
            bt = b + a[a.size() - 1];
            string tt = at + "," + bt + "," + c;
            if (!buff.count(tt)) {
                buff[tt] = t.k + 1;
                qu.push(node(tt, t.k + 1));
            }

            ct = c + a[a.size() - 1];
            tt = at + "," + b + "," + ct;
            if (!buff.count(tt)) {
                buff[tt] = t.k + 1;
                qu.push(node(tt, t.k + 1));
            }
        }

        if (b.size() > 0) {
            bt = b;
            bt.pop_back();

            ct = c;
            at = a + b[b.size() - 1];
            string tt = at + "," + bt + "," + c;
            if (!buff.count(tt)) {
                buff[tt] = t.k + 1;
                qu.push(node(tt, t.k + 1));
            }
            ct = c + b[b.size() - 1];
            tt = a + "," + bt + "," + ct;
            if (!buff.count(tt)) {
                buff[tt] = t.k + 1;
                qu.push(node(tt, t.k + 1));
            }
        }

        if (c.size() > 0) {
            ct = c;
            ct.pop_back();

            at = a + c[c.size() - 1];
            string tt = at + "," + b + "," + ct;
            if (!buff.count(tt)) {
                buff[tt] = t.k + 1;
                qu.push(node(tt, t.k + 1));
            }
            bt = b + c[c.size() - 1];
            tt = a + "," + bt + "," + ct;
            if (!buff.count(tt)) {
                buff[tt] = t.k + 1;
                qu.push(node(tt, t.k + 1));
            }
        }
    }

    debug(as, bs, cs);
}
int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}