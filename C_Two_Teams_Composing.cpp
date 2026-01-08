#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
void solve() {
    int n, a, uni = 0, maxs = 0;
    unordered_map<int, int> vis;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (!vis.count(a)) {
            vis[a] = 1;
            uni++;
        } else {
            vis[a]++;
        }
        if(vis[a] > maxs) {
            maxs = vis[a];
        }
    }
    if(n == 1) {
        cout << 0 << endl;
    }else if(uni == 1) {
        cout << 1 << endl;
    } else {
        if(maxs <= uni - 1) {
            cout << maxs << endl;
        } else {
            cout << min(maxs - 1, uni) << endl;
        }
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