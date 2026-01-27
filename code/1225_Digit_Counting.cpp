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
void addDigit(vector<int> &count, int num) {
    while (num) {
        count[num%10]++;
        num /= 10;
    }
}
void solve() {
    int n;
    vector<int> count(11);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        addDigit(count, i);
        debug(count);
    }
    cout << count[0];
    for (int i = 1; i < 10; i++) {
        cout << " " << count[i];
    }
    cout << endl;
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