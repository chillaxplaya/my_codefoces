#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
int a[200005];
int twoFind(int x, int n) {
    int l = 0;
    int r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if(a[mid] <= x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
void solve() {
    int m, n, x;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < m; i++) {
        cin >> x;
        cout << twoFind(x, n) << " ";
    }
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