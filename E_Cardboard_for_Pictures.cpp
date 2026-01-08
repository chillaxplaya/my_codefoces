/*
 * Author: playa
 * Created: ${CURRENT_YEAR}-${CURRENT_MONTH}-${CURRENT_DATE} ${CURRENT_HOUR}:${CURRENT_MINUTE}
 */

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
ll s[200005];
bool checkLegal(ll w, ll c, int n) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ((s[i] + w) * (s[i] + w));
        if (sum > c) {
            return false;
        }
    }
    return true;
}
void solve() {
    int n;
    long long c;
    cin >> n;
    cin >> c;
    long long cc = sqrt(c);
    while(cc * cc < c) {
        cc++;
    }
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    long long l = 0, r = cc;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if  (checkLegal(mid, c, n)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << (l - 1) / 2 << endl;

}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}