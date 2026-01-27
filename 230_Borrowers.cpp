#include <algorithm>
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
struct book{
    string name;
    string author;
    bool operator<(const book &a) const {
        return (author != a.author) ?  (author < a.author) : (name < a.name);
    }
    int ct; // 2: in  1: return not in shelve   0: borrow
};
book getinfo(string a) {
    book res;
    size_t l = a.find_first_of("\"");
    size_t r = a.find_last_of("\"");
    res.name = a.substr(l + 1, r - l - 1);
    res.author = a.substr(r + 5, a.size() - r - 6);
    res.ct = 2;
    return res;
    
}
void cmdbt(vector<book> &shelve,string b,const int &ct) {
    for (auto &e : shelve) {
        if (e.name == b) {
            e.ct = ct;
            return;
        }
    }
}
int findpre(vector<book> &shelve, int i) {
    for (; i >= 0; i--) {
        if(shelve[i].ct == 2) {
            return i;
        }
    }
    return -1;
}
void cmdshe(vector<book> &shelve) {
    for (int i = 0; i < shelve.size(); i++) {
        if (shelve[i].ct == 1) {
            int tres = findpre(shelve, i);
            if (tres != -1) {
                cout << "Put \"" << shelve[i].name 
                    << "\" after \"" << shelve[tres].name <<"\"\n";
            } else {
                //Put title first
                cout << "Put \"" << shelve[i].name << "\" first\n";
            }
            shelve[i].ct = 2;
        }
    }
}
void solve() {
    string bookinfo;
    vector<book> shelve;
    while (getline(cin, bookinfo) && bookinfo != "END") {
        shelve.push_back(getinfo(bookinfo));
    }
    sort(all(shelve));
    string cmd, b;
    while (cin >> cmd && cmd != "END") {
        debug(cmd);
        if (cmd == "BORROW") {
            cin.get();
            getline(cin, b);
            b.pop_back();
            b.erase(b.begin());
            cmdbt(shelve, b, 0);
        } else if (cmd == "RETURN") {
            cin.get();
            getline(cin, b);
            b.pop_back();
            b.erase(b.begin());
            cmdbt(shelve, b, 1);
        } else if (cmd == "SHELVE") {
            cmdshe(shelve);
            cout << "END\n";
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