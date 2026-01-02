#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define ll long long
int a[1000005];
int twofind(int *a, int l, int r, int q) {
    while(l < r) {
        int mid = l + ((r - l) / 2);
        if(a[mid] > q) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return  l;
}
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int q, m;
    cin >> q;
    while (q--) {
        cin >> m;
        cout << "ans :" <<twofind(a, 0, n, m) << endl;
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