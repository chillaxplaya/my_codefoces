
#include <cstdio>
#include <string>
#include <map>
#include <iostream>
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
char m[10][10];
map<char, pair<int, int>> op;
bool isLegal(int x, int y) {
    if(x < 0 || x > 4)
        return false;
    if(y < 0 || y > 4)
        return false;
    return true;
}
bool isLeagal(char s[]) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            count++;
        }
    }
    return count == 4 || count == 5;
}
void solve() {
    int casec = 1;
    while (1) {
        fgets(m[0], 9, stdin);
        if (m[0][0] == 'Z') {
            return;
        }
        for (int i = 1; i < 5; i++) {
            fgets(m[i], 9, stdin);
            if(!isLeagal(m[i])) i--;
        }
        int bi, bj;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (m[i][j] == ' ') {
                   bi = i;
                   bj = j; 
                }
            }
        }
        debug(bi, bj);
        char o;
        bool ok = true;
        while ((o = getchar()) != '0') {
            if (!op.count(o)) continue;
            int ni = bi + op[o].first;
            int nj = bj + op[o].second;
            debug(ni, nj);
            if (isLegal(ni, nj)) {
                swap(m[bi][bj], m[ni][nj]);
                bi = ni;
                bj = nj;
            } else {
                
                ok = false;
            }
        }

        //Puzzle #1:
        if (casec != 1) {
            cout << endl;
        }
        cout << "Puzzle #" << casec++ << ":" << endl;
        if (ok) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if(j) cout << " ";
                    cout << m[i][j];
                }
                cout << endl;
            }
        } else {
            cout << "This puzzle has no final configuration." << endl;
        }
        while ((o = getchar()) != '\n') {
            if (o == 'Z')
                return;
        }
    }
    
}
void init() {
    op['A'] = {-1, 0};
    op['B'] = {1, 0};
    op['L'] = {0, -1};
    op['R'] = {0, 1};
}
int main() {
    // srand(time(0));
    init();
    // ios::sync_with_stdio(0);
    // cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}