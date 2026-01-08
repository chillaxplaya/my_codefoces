#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
    int n, x;
    cin >> n;
    cin >> x;
    int l = x, r = x;
    bool flag = false;
    for (int i = 1; i < n; i++) {
        cin >> x;
        if (x == r + 1) r = x;
        else if (x == l - 1) l = x;
        else flag = true;
    }
    if (flag) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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