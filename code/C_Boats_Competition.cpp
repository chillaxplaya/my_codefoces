#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()
#define ll long long
int getgroup(vector<int> &a, int s) {
    int sum = 0;
    for(int i = 0; i < a.size(); i++) {
        if(i < s && i < a.size() && s - i < a.size() && s - i < s) {
            if(a[i] > 0 && a[s - i] > 0) {
                sum += min(a[i], a[s - i]);
                // if(i == s - i) sum += a[i];
            }
        } else if(i >= s) {
            break;
        }
    }
    return sum / 2;
}
void solve() {
    int n;
    cin >> n;
    debug(n);
    if (n == 1) {
        cin >> n;
        cout << 0 << endl;
        return;
    }
    vector<int> a(n);
    vector<int> count(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        count[a[i]]++;
    }
    sort(all(a));
    int ans = 0;
    for (int i = a[n - 1] + a[n - 2]; i > 0; i--) {
        ans = max(ans, getgroup(count, i));
        
    }
    
    cout << ans << endl;
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