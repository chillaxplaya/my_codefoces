#include <bits/stdc++.h>
#include <cstdio>
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
string getmins(string s) {
    for (auto &e : s) {
        e = tolower(e);
    }
    int l = s.size();
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l - 1; j++) {
            if (s[j] > s[j + 1]) {
                swap(s[j],s[j + 1]);
            }
        }
    }
   
    return s;
}
void solve() {
    char c;
    string s;
    s.clear();
    unordered_map<string, string> revisedword;;
    map<string, int> minword;
    while ((c = getchar()) != EOF) {
        
        if (isalpha(c)) {
            s += c;
        } else if(!s.empty()){
            
            string mins = getmins(s);
            revisedword[mins] = s;
            minword[mins]++;
            s.clear();
            if(c == '#') { break; }
        }
    }
    set<string> words;
    for (auto e : minword) {
        if (e.second == 1)
            words.insert(revisedword[e.first]);
    }
    for (auto e : words) {
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