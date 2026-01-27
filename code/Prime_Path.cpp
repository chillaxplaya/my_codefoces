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
int p[10005];
unordered_set<int> primes;
void initprime() {
    for (int i = 2; i < 10000; i++) {
        if(p[i] == 0) {
            for (int j = i * i; j < 10000; j += i) {
                p[j] = 1;
            }
        }
    }
    

    for(int i = 1000; i < 10000; i++) {
        if(!p[i]) { primes.insert(i); };
    }
}
int step[10005];
int p10[4] = {1, 10, 100 ,1000};
void solve() {
    memset(step, 0, sizeof(step));
    int x, y;
    queue<int> qu;
    initprime();
    cin >> x >> y;
    qu.push(x);
    step[x] = 1;
    while (!qu.empty()) {
        int tx = qu.front();
        qu.pop();
        debug(tx, step[tx]);
        if (tx == y) {
            cout << step[tx] - 1 << "\n";
            return;
        }
        for (int i = 0; i < 4; i++) {
            //9999 
            int tx1 = tx - (tx / p10[i]) % 10 * p10[i];
            for (int j = 0; j < 10; j++) {
                int tx2 = tx1 + j * p10[i];
                if (step[tx2] == 0 && primes.count(tx2)) {
                    step[tx2] = step[tx] + 1;
                    qu.push(tx2);
                }
            }
        }
    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}