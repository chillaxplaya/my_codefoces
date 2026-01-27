#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n)                                           \
    cerr << "[" << #a << "] = {";                                 \
    for (int i = 0; i < (n); i++) cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

#define all(x) (x).begin(), (x).end()
#define ll long long
int findpile(vector<vector<int>> &pile, int x, int n) {
    for (int i = 0; i < n; i++) {
        for (auto e : pile[i]) {
            if (e == x) { return i; }
        }
    }
    return -1;
}
void initpile(vector<vector<int>> &pile, int x, int n) {
    int p = findpile(pile, x, n);
    int index = 0;
    int m = pile[p].size();
    for(; index < m; index++) {
        if(pile[p][index] == x) {
            break;
        }
    }
    index++;
    for (; index < m; index++) {
        pile[pile[p][index]].push_back(pile[p][index]);
    }
    while (pile[p].back() != x) {
        pile[p].pop_back();
    }
}
void movepilextoy(vector<vector<int>> &pile, int x, int y, int n) {
    int p1 = findpile(pile, x, n);
    int p2 = findpile(pile, y, n);
    int index = 0;
    int m = pile[p1].size();
    for(; index < m; index++) {
        if(pile[p1][index] == x) {
            break;
        }
    }
    for (; index < m; index++) {
        pile[p2].push_back(pile[p1][index]);
    }
    while (pile[p1].back() != x) {
        pile[p1].pop_back();
    }
    pile[p1].pop_back();
}
void print(vector<vector<int>> &pile, int n) {
    for (int i = 0; i < n; i++) {
        cout << i << ":";
        for (auto e : pile[i]) {
            cout << " " << e;
        }
        cout << endl;
    }
}
void solve() {
    int n, x, y;
    cin >> n;
    debug(n);
    string cmd1, cmd2;
    vector<vector<int>> pile(n);
    for (int i = 0; i < n; i++) {
        pile[i].push_back(i);
    }
    while (cin >> cmd1) {
        
        if (cmd1 == "quit") { break; }
        
        cin >> x >> cmd2 >> y;
        int p1 = findpile(pile, x, n);
        int p2 = findpile(pile, y, n);
        if (p1 == p2) { continue; }
        if (cmd1 == "move" && cmd2 == "onto") {
            initpile(pile, x, n);
            initpile(pile, y, n);
            movepilextoy(pile, x, y, n);
        } else if (cmd1 == "move" && cmd2 == "over") {
            initpile(pile, x, n);
            movepilextoy(pile, x, y, n);
        } else if (cmd1 == "pile" && cmd2 == "onto") {
            initpile(pile, y, n);
            movepilextoy(pile, x, y, n);
        } else if (cmd1 == "pile" && cmd2 == "over") {
            movepilextoy(pile, x, y, n);
        }
    }
    print(pile, n);
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}