#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a,b;
    cin >> a >> b;
    int ta = a;
    int tb = b;
    int t = 1,sum = 0,flag = 1;
    while(a >= 0 && b >= 0) {
        if(flag) {
            a -= t;
        } else {
            b -= t;
        }
        flag = 1 - flag;
        t = t << 1;
        sum ++;
    }
    int ans = sum - 1;
    a = tb;
    b = ta;
    t = 1,sum = 0,flag = 1;
    while(a >= 0 && b >= 0) {
        if(flag) {
            a -= t;
        } else {
            b -= t;
        }
        flag = 1 - flag;
        t = t << 1;
        sum ++;
    }
    ans = max(ans, sum - 1);
    cout << ans <<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 0;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}