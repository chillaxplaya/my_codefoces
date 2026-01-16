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
bool blank = true;
void solve() {
    string s;
    cin >> s;
    int size = s.size();
    if(!blank) {
        cout << endl;
    }
    blank = false;
    for (int i = 1; i <= size; i++) {
        if(size % i) continue;
        for (int j = i; j < size; j++) {
            if (s[j] != s[j - i]) {
                break;
            }
            if(j == size - 1) {
                cout << i << endl;
                return;
            }
        }
    }
    
    
    cout << size << endl;
    
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