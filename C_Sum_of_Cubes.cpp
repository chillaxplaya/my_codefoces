#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
vector<ll> triblen;
unordered_set<ll> triblev;
void initTrible() {
    for (int i = 1; i <= 10000; i++) {
        ll a = 1LL * i * i * i;
        triblen.push_back(a);
        triblev.insert(a);
    }
}
void solve() {
    ll n;
    cin >> n;
    for (auto e : triblen) {
        if(e > n) {
            break;
        }
        if (triblev.count(n - e)) {
            cout << "YES" << endl;
            return ;
        }
    }
    cout << "NO" << endl;
}
int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    initTrible();
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}