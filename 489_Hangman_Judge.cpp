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

void solve() {
    int x;
    while (cin >> x && x != -1) {
        string a, b;
        set<char> ea;
        set<char> eb;
        vector<int> amap(27);
        bool lose = false;
        cin >> a >> b;
        for (auto e : a) {
            amap[e - 'a']++;
            ea.insert(e);
        }
        int kill = 0;
        int sum = a.size();
        for (auto e : b) {
            if (!ea.count(e) && !eb.count(e)) {
                kill++;
                if (sum && kill >= 7) {
                    lose = true;
                }
            }
            sum -= amap[e - 'a'];
            amap[e - 'a']  = 0;
            eb.insert(e);
        }
        cout << "Round " << x << endl;
        if (lose) {
            cout << "You lose." << endl;
            continue;
        }
        cout << (sum == 0 ? "You win." : "You chickened out.") << endl;
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