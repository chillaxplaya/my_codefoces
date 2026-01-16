#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n) \
    cerr << "[" << #a << "] = {"; \
    for (int i = 0; i < (n); i++) cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";
/*
76/25 = 3.04(0)
   1 = number of digits in repeating cycle
5/43 = 0.(116279069767441860465)
   21 = number of digits in repeating cycle
1/397 = 0.(00251889168765743073047858942065491183879093198992...)
   99 = number of digits in repeating cycle
*/

#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        map<int, int> vis;
        vector<int> post;
        int save_n = n;
        int save_m = m;
        int i = 0;
        int ans = 1;
        bool all = false;
        int a = n / m;
        n %= m;
        int l = 0x3fff;
        int r = 0x3fff;
        while (1) {
            if (n == 0) {
                all = true;
                post.push_back(0);
                l = i;
                r = i + 1;
                break;
            }
            if (vis.count(n)) {
                ans = i - vis[n];
                l = vis[n];
                r = (i);
                break;
            }
            vis[n] = (i++);
            n *= 10;
            post.push_back(n / m);
            n %= m;
        }

        //print
        printf("%d/%d = ", save_n, save_m);
        printf("%d.", a);
        int l1 = min((int)post.size(), l);
        for (int i = 0; i < l1; i++) {
            printf("%d", post[i]);
        }
        putchar('(');
        int rr;
        rr = r;
        if(r - 0 >= 50) {
            rr = l + 50;
        }
        for(int i = l; i < rr; i++) {
            printf("%d",post[i]);
        }
        if(r - l >= 50)
            printf("...");
        putchar(')');
        putchar('\n');
        printf("   %d = number of digits in repeating cycle\n\n", r - l);
        debug(r - l);
    }
    
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