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


#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
struct Lesson {
    string name;
    int deadline;
    int cost;
};
void solve() {
    int n;
    cin >> n;
    int mask = 1 << n;
    vector<Lesson> lss(n);
    vector<int> dp(mask, 0x3f3f3f3f);
    dp[0] = 0;
    vector<int> cost(mask);
    vector<int> pre(mask);
    vector<int> choosed(mask, -1);
    for (int i = 0; i < n; i++) {
        cin >> lss[i].name >> lss[i].deadline >> lss[i].cost;
    }
    for (int now_state = 1; now_state < mask; now_state++) {
        for (int j = 0; j < n; j++) {
            if(now_state & (1 << (j))) {
                int pre_state = now_state ^ (1 << (j));
                int now_cost = cost[pre_state] + lss[j].cost;
                int now_penalty = dp[pre_state] + (max(0,now_cost - lss[j].deadline));
                if (now_penalty <= dp[now_state]) {
                    dp[now_state] = now_penalty;
                    cost[now_state] = now_cost;
                    pre[now_state] = pre_state;
                    choosed[now_state] = j; 
                    debug(now_state, pre_state, lss[choosed[now_state]].name);
                }
            }
        }
    }
    vector<string> res;
    int qstate= mask - 1;
    while(qstate != 0) {
        res.push_back(lss[choosed[qstate]].name);
        qstate = pre[qstate];
    }
    reverse(all(res));
    cout << dp[mask - 1] << endl;
    for(string& s : res) {
        cout << s << "\n";
    }
    debug("----");
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