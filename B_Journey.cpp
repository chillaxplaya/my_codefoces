#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
    int n, a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    int sum = a[0] + a[1] + a[2];
    a[1] = a[0] + a[1];
    a[2] = a[1] + a[2];
    int ans = n / sum;
    n %= sum;
    if (n == 0) {
        cout << ans * 3 << endl;
        return ;
    }
    for(int i = 0; i < 3; i++) {
        if(n <= a[i]) {
            cout << ans * 3 + 1 + i << endl;
            return ;
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