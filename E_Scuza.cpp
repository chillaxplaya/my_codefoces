#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
ll maxan[200005];
ll prean[200005];
ll an[200005];
int lowerBound(ll *a, int l1, int r1, int q) {
    int l = l1;
    int r = r1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] <= q) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l - 1;
}
void solve() {
    int n, q, x, maxx = 0;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> an[i];
        if(an[i] > maxx) {
            maxx = an[i];
        }
        maxan[i] = maxx;
        an[i] = ((i == 0) ? an[i] : an[i - 1] + an[i]);
        
    }
    DEBUG_ARR(maxan, n);
    for(int i = 0; i < q; i++) {
        cin >> x;
        int qq = lowerBound(maxan, 0, n, x);
        DEBUG(qq);
        if(qq == -1) {
            cout << 0 << " ";
        } else {
            cout << an[qq] << " ";
        }
    }
    cout << endl;
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