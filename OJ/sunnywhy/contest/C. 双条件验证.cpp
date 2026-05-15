/*
C. 双条件验证
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-16 19:42:08
user: playa
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define endl '\n'
typedef pair<int, int> pi;
map<ll, int> dis;

/*
*/
void justdoit() {
    ll p, a;
    cin >> p >> a;
    bool isprim = true;
    for (ll i = 2; i * i <= p; i++) {
        if (p % i == 0) {
            isprim = false;
        }
    }
    if (isprim) {
        cout << "no";
        return;
    }
    ll cnt = 1;
    ll pp = p;
    // for (int i = 1; i <= pp; i++) {
    //     cnt *= a;
    //     cnt %= p;
    //     if (cnt == 0) {
    //         break;
    //     }
    //     if (dis.count(cnt)) {
    //         if ((pp - i) % (i - dis[cnt]) == 0) {
    //             break;
    //         }
    //         pp = (pp - i) % (i - dis[cnt]) + i;
    //         dis[cnt] = (i);
    //     } else {
    //         dis[cnt] = (i);
    //     }
    // }
    ll aa = a;
    while (pp) {
        
        if (pp & 1) {
            cnt *= aa;
            cnt %= p;
        }
        aa = (aa * aa) % p;
        pp /= 2;
    }
    cout << (cnt == a ? "yes" : "no");
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        justdoit();
    return 0;
}