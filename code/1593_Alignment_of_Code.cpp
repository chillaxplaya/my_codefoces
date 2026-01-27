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
int maxlen[300005];
vector<vector<string>> literal;
void formatprint(string s, int l) {
    cout << s;
    int l1 = l - s.size();
    for (int i = 0; i < l1; i++) {
        cout << ' ';
    }
}
void solve() {
    string s, word;
    while (getline(cin, s)) {
        stringstream sin(s);
        int idx = 0;
        literal.push_back(vector<string>());
        while (sin >> word) {
            if (word.size() > maxlen[idx]) {
                maxlen[idx] = word.size();
            }
            literal.back().push_back(word);
            idx++;

        }
        
    }
    for (auto e : literal) {
        for(int i = 0; i < e.size(); i++) {
            if(i != e.size() - 1)
                formatprint(e[i], maxlen[i] + 1);
            else
                 cout << e[i];
        }
        cout << "\n";
    }
    debug_arr(maxlen, 10);
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