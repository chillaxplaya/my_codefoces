#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
int a[10005], b[10005];
void solve() {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    int i = 0, j = 0;
    int ans = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= 1) {
            DEBUG(i);
            DEBUG(a[i]);
            DEBUG(b[j]);
            ans++;
            i++;
            j++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            i++;
        }
    }
    cout << ans << endl;
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}