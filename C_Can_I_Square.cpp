#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
set<long long> sqd;
void solve() {
    int n;
    cin >> n;
    ll sum = 0, x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
    }
    ll t = sqrt(sum);
    if(t * t == sum) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    for(int i = 1; i < 200001; i++) {
        sqd.insert(1LL * i * i);
    }
    while(T--) solve();
    return 0;
}