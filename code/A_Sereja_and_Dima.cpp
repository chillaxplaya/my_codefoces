#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
int a[400005];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int s = 0, d = 0;

    int l = 0, r = n - 1;
    int flag = 1;
    while (l <= r) {
        int maxrl;
        if (a[l] > a[r]) {
            maxrl = a[l];
            l++;
        } else {
            maxrl = a[r];
            r--;
        }
        if (flag) {
            s += maxrl;
        } else {
            d += maxrl;
        }
        flag = 1 - flag;
    }
    cout << s << " " << d << endl;
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}