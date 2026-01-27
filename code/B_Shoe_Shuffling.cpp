#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
    int n;
    int x, pre;
    bool flag = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i != 0 && x != pre) {
            flag = true;
        }
        pre = x;
    }
    if(!flag) {
        cout << n;
        for (int i = 1; i < n; i++) {
            cout << " " << i;
        }
    } else cout << -1;
    cout << endl;
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