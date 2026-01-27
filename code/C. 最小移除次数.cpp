
//https://sunnywhy.com/camp/3415/model/3611?itemId=3885
//
#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
int vis[300005];
int dfs(vector<vector<int>> &adj,int x) {
    vis[x] = 1;
    int sum = 0;
    int maxd = -0x3ffff;
    int count = 0;
    for(auto e : adj[x]) {
        if(!vis[e]){
            count++;
            int t = dfs(adj, e);
            sum += t;
            maxd = max(maxd, t);
        }
    }
    if(count == 0) {
        debug(x,1);
        return 1;
    } else if (count == 1) {
        debug(x,sum);
        return sum + 1;
    }
    if (x == 1) {
        return sum + 1  - maxd;
    }
    debug(x,sum ,maxd );
    return sum + 1;
}
void solve1() {
    int n, x, y;  
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(adj[1].size() == 1) {
        cout << 1;
        return ;
    }
    debug(adj);
    cout << dfs(adj, 1);
}
void solve2() {
    int n, a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    cout << (n - 2) * min(a[0],min(a[1], a[2])) + min(a[0], a[1]);
}
int calx(int x) {
    int res = 0;
    while (x) {
        res += (x%10);
        x /= 10;
    }
    return res;
}
void solve3() {
    int l, r, x, absm = 0x3ffffff, ans;
    cin >> l >> r >> x;
    int xx = calx(x);
    debug(xx);
    for (int i = l; i <= r; i++) {
        int t = calx(i);
        debug(t);
        if(abs(t - xx) < absm) {
            absm = abs(t - xx);
            ans = i;
        }
    }
    cout << ans;
}
int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve2();
    return 0;
}