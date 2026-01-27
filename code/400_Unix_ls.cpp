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

/*
0   5
1   6
2   7
3   8
4   9
*/

// 19 / 5
#define all(x) (x).begin(), (x).end()
#define ll long long
void solve() {
    int n;
    string f;
    vector<string> filev;
    while (cin >> n) {
        cout << "------------------------------------------------------------\n";
        filev.clear();
        int maxlen = 0;
        for (int i = 0; i < n; i++) {
            cin >> f;
            filev.push_back(f);
            maxlen = max(maxlen, (int)(f.size()));
        }
        sort(all(filev));
        int col = (60 - maxlen) / (maxlen + 2) + 1;
        int row = n / col;
        if (n % col) row++;
        debug(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int np = i + j * row;
                if(np >= filev.size()) continue;
                cout << filev[i + j * row];
                int blankl = maxlen + 2 - filev[i + j * row].size();
                if (j == col - 1) continue;
                for(int i = 0; i < blankl; i++) {
                    cout << ' ';
                }
            }
            cout << endl;
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