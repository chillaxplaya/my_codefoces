#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
string rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
#define debug_arr(a, n) \
    cerr << "[" << #a << "] = {"; \
    for (int i = 0; i < (n); i++) cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";


#define all(x) (x).begin(), (x).end()
#define ll long long
char cstring[1005];
bool isrp(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
char mirrorc(char c) {
    if (c >= 'A' && c <= 'Z') {
        return rev[c - 'A'];
    }
    if (c >= '1' && c <= '9')
        return rev[c - '1' + 26];
    return ' ';
}
bool isms(string s) {
    int l = 0, r = s.size() - 1;
    while (l <= r) {
        if (mirrorc(s[l]) != s[r]) {
            debug(mirrorc(s[l]));
            debug(s[r]);
            return false;
        }
        l++;
        r--;
    }
    return true;
}
void solve() {
    char c;
    bool first = true;
    while (scanf("%s",cstring) == 1) {
        string s(cstring);
        bool ms = isms(s);
        bool rp = isrp(s);
        debug(ms);
        first = false;
        if (ms && rp) {
            cout << s << " -- is a mirrored palindrome.";
        } else if (ms) {
            cout << s << " -- is a mirrored string.";
        } else if (rp) {
            cout << s << " -- is a regular palindrome.";
        } else {
            cout << s << " -- is not a palindrome.";
        }
        cout << endl << endl;
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