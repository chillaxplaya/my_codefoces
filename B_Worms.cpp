#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
struct itv{
    int l,r;
    itv(int l1, int r1) : l(l1), r(r1) {}
};
int twofind(vector<itv> & b, int l, int r, int q) {
    while (l < r) {
        int mid = l + ((r - l) / 2);
        // DEBUG(mid);
        if(q < b[mid].l) {
            r = mid;
            continue;
        }
        if(q > b[mid].r) {
            l = mid + 1;
            continue;
        }
        return mid + 1;
    }
    return l + 1;
}
void solve() {
    int n;
    cin >> n; 
    vector<itv> b;
    int a;
    cin >> a;
    int l = 1;
    int r = a;
    b.push_back(itv(l, r));
    for(int i = 1; i < n; i++) {
        cin >> a;
        l = b[i-1].r + 1;
        r = b[i-1].r + a;
        b.push_back(itv(l, r));
        // DEBUG(l);
        // DEBUG(r);
    }
    int m,q;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> q;
        
        cout << twofind(b, 0, n, q) << endl; 
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