#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    int bc = 0, wc = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == 'B') bc++;
        else wc++;
    }
    int ans = wc;
    for (int i = 0, j = k; j < n; i++, j++) {
        if (s[i] == 'B') bc--;
        else wc--;
        if (s[j] == 'B') bc++;
        else wc++;
        ans = min(ans, wc);
    }
    cout << ans << endl;
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