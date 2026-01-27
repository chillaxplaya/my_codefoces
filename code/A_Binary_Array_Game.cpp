#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
/**  11    0
     00    1
     10    1
     01    1



**/
void solve() {
    int n, x;
    cin >> n;
    bool a0 = false, an = false;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i == 0 && x == 0) {
            a0 = true;
        }
        if (i == n - 1 && x == 0) {
            an = true;
        }
    }
    if (a0 && an) {
        cout << "bob" << endl;
    } else {
        cout << "alice" << endl;
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