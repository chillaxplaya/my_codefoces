#include <bits/stdc++.h>
#include <vector>
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

void solve() {
    string s;
    unordered_map<string, int> dic;
    vector<string> words;
    while (cin >> s) {
        dic[s] = 1;
        words.push_back(s);
    }
    for (auto e : words) {
        for (int i = 1; i < e.size(); i++) {
            string a = e.substr(0, i);
            string b = e.substr(i, e.size() - i);
            if (dic.count(a) && dic.count(b)) {
                cout << e << "\n";
                break;
            }
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