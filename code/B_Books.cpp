#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"
#define all(x) (x).begin(), (x).end()
#define ll long long
int a[100005];
int b[100005];
int twofind(int *a, int l, int r, int q) {
    while (l < r) {
        int mid = (l + (r - l) / 2);
        if(q >= a[mid]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l - 1;
}
void solve() {
    int n, t;
    cin >> n >> t;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    int r = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        while(r < n && sum + a[r] <= t) {
            sum += a[r];
            r++;
        }
        ans = max(ans, r - i);
        sum -= a[i];
    }
    cout << ans;
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