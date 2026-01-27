#include <bits/stdc++.h>
#include <string>
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
void cmd_borrow(vector<pair<string,int>> &shelve,string book) {
    for (auto e : shelve) {
        if (e.first == book) {
            e.second = 0;
        }
    }
}
void cmd_return(vector<pair<string,int>> &shelve,string book) {
    for (auto e : shelve) {
        if (e.first == book) {
            e.second = 2;
        }
    }
}
void solve() {
    string bookau;
    vector<pair<string,int>> shelve;
    while (getline(cin, bookau) && bookau != "END") {
        size_t t1 = bookau.find_first_of("\"");
        size_t t2 = bookau.find_last_of("\"");
        string book = bookau.substr(t1, t2 - t1 + 1);
        shelve.push_back({book, 1});
    }
    string cmd, book;
    while (cin >> cmd && cmd != "END") {

        if (cmd == "BORROW") {
            cin.get();
            getline(cin, book);
            cmd_borrow(shelve, book);
        } else if(cmd == "RETURN") {
            cin.get();
            getline(cin, book);
        } else if(cmd == "SHELVE") {
            
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