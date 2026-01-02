#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll plimit = 1000001;
ll prime[plimit];
set<ll> getprime() {
    for(int i = 2; i < plimit; i++) {
        if(!prime[i]) {
            for(ll j = 1LL * i * i; j < plimit; j+=i) {
                //cout << j << endl;
                prime[j] = 1;
            }
        }   
    }
    set<ll> tprime;
    for(int i = 2; i < plimit; i++) {
        if(!prime[i]) {
            tprime.insert(1LL * i * i);
        }
    }
    return tprime;
}
void solve() {
    ll x;
    int n; cin >> n;
    set<ll> primeGet(getprime());
    while(n--) {
        cin >> x;
        if(primeGet.count(x)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    
    solve();
    return 0;
}