#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define ll long long
int a[1005];
void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    a[0] = 0;
    a[n + 1] = k;
    double ans = -1e18;
    for(int i = 1; i <= n; i++) {
        double maxt = max((double)a[i] - a[i-1], (double)a[i+1] - a[i]);
        if(maxt > ans) ans = maxt; 
    }
    ans /= 2;
    if(((double)a[1] - a[0]) > ans) ans = (double)a[1] - a[0];
    if(((double)a[n+1] - a[n]) > ans) ans = (double)a[n+1] - a[n];
    
    printf("%.10lf",ans);
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