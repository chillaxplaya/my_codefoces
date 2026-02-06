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
void init12(vector<int> &res, int n) {
    for (int i = 1; i * i <= n; i++) {
        for (int j = i + 1; j * j <= n; j++) {
            if (i * i + j * j <= n)
                res.push_back(i * i + j * j);
        } 
    }
} 
void solve() {
    vector<int> nums;
    int n;
    cin >> n;
    init12(nums, n);
    sort(all(nums));
    set<int> b;
    for (int i = 0; i < nums.size(); i++) {
        if ((i > 0 && nums[i - 1] == nums[i]) || (i < n - 1 && nums[i + 1] == nums[i])) {
            //do nothing
        } else {
            b.insert(nums[i]);
        }
    }
    cout << b.size() << "\n";
    for (auto &e : b) {
        cout << e << ' ';
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