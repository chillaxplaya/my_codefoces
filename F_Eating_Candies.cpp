#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
int w[200005];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    int sumi = w[0];
    int sumj = w[n - 1];
    int ans = 0;
    for(int i = 0, j = n - 1; i < j;) {
        if(sumi == sumj) {
            ans = i + 1 + n - j;
            i++;
            j--;
            sumj += w[j];
            sumi += w[i];
        } else if (sumi > sumj) {
            j--;
            sumj += w[j];
        } else {
            i++;
            sumi += w[i];
        }
    }
    cout << ans << endl;
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