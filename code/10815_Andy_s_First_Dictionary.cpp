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
int isAlpha(char c) {
    if (c >= 'a' && c <= 'z') { return 1; }
    if (c >= 'A' && c <= 'Z') { return 2; }
    return 0;
}
void solve() {
    char c;
    string s = "";
    set<string> word;
    while((c = getchar()) != EOF) {
        int isa = isAlpha(c);
        if (isa == 1) {
            s += c;
        } else if (isa == 2) {
            s += (c - 'A' + 'a');
        } else {
            if(!s.empty()) {
                word.insert(s);
                s.clear();
            }
        }
        debug(s);
    }
    if(s.size() > 0) {
        word.insert(s);
    }
    for (auto e : word) {
        printf("%s\n", e.c_str());
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