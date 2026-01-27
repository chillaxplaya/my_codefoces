#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;
    if (n > k) {
        if (n > (n/k) * k) {
            k = (n/k + 1) * k;
            cout << k / n + 1 << endl;
        } else {
            k = (n/k) * k;
            cout << k / n << endl;
        }
    } else {
        if (k % n) {
            cout << k / n + 1 << endl;
        } else {
            cout << k / n << endl;
        }
    }
    
}
int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}