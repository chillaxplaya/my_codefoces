#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
    int l, r;
    cin >> l >> r;
    int d = r - l;
    int sum = 0;
    int ans = 0;
    for(int i = 0; sum <= d; i++) {
        sum += i;
        ans++;
    }
    cout << ans - 1 << endl;
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