#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
bool checkLegal(int a, int b, int oa) {
    if(oa * 2 <= b && (a - oa) / 2 <= (b - oa * 2)) return true;
    return false;
}
void solve() {
    int a, b;
    cin >> a >> b;
    if(a < b) {
        swap(a, b);
    }
    int l = 0, r = a + 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if(checkLegal(a, b, mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (l) {
        cout << (l - 1) + min((a - l + 1) / 2, (b - (l - 1) * 2)) << endl;
    } else {
        cout << min(a / 2, b) << endl;
    }
    
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