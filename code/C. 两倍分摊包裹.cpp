#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long

int dp[10005];
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i]; 
    }
    if (sum % 3) {
        cout << "No\n";
        return;
    }
    sum /= 3;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= a[i]; j--) {
            if(dp[j - a[i]] == 1) dp[j] = 1;
        }
    }
    if (dp[sum] == 1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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