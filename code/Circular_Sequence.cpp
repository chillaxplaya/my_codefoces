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
string getNext(int index, string &s) {
    int n = s.size();
    string a = "";
    for (int i = 0; i < n; i++) {
        a += s[(i + index) % n];
    }
    return a;
}
bool cmpS(string &a, string &b) {
    int l = a.size();
    for (int i = 0; i < l; i++) {
        if (a[i] < b[i]) {
            return true;
        }
        if (a[i] > b[i]) {
            return false;
        }
    }
    return false;
}
void solve() {
    string s;
    cin >> s;
    string ans = s;
    string t;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        t = getNext(i, s);
        if (cmpS(t, ans)) {
            ans = t;
        }
    }
    cout << ans << endl;
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}