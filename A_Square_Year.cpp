#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
unordered_set<int> sqt;
bool is_sqt(long long x) {
    long long t = llround(sqrt((long double)x));
    return t * t == x;
}
void solve() {
    long long x;
    cin >> x;
    if (is_sqt(x)) {
        cout << 0 << " " << llround(sqrt((long double)x)) << endl;
    } else {
        cout << -1 << endl;
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