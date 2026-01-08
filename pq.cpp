#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
    int n, ans = 0;
    string a, b;
    cin >> n;
    cin >> a >> b;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != b[i] && a[i + 1] != b[i + 1] && a[i] != a[i + 1]) {
            swap(a[i], a[i + 1]);
            ans++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            ans++;
        }
    }
    cout << ans << endl;
}
int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}