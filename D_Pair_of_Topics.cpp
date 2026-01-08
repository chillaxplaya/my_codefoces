#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
int a[200005];
int b[200005];
void solve() {
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] + a[j] > b[i] + b[j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
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