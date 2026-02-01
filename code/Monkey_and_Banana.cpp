#include <bits/stdc++.h>
#include <vector>
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
struct Cube{
    int x, y, z;
    Cube() {}
    Cube(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
    void setVal(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    }
    bool operator<(const Cube& c) const {
        return x == c.x ? (y == c.y ? z > c.z : y > c.y) : x > c.x;
    }
    
}cube[100];
ostream& operator<<(ostream& os, const Cube& c) {
    return os << "x :" << c.x << " y: " << c.y << " z: " << c.z; 
}
bool okup(const Cube &a,const Cube &b) {
    return a.x < b.x && a.y < b.y;
}
void solve() {
    int n, x, y, z;
    int rd = 1;
    while (cin >> n && n) {
        vector<int> dp(n * 6);
        debug(6 * n);
        vector<Cube> vcube;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> z;
            vcube.push_back(Cube(x, y, z));
            vcube.push_back(Cube(x, z, y));
            vcube.push_back(Cube(y, x, z));
            vcube.push_back(Cube(y, z, x));
            vcube.push_back(Cube(z, x, y));
            vcube.push_back(Cube(z, y, x));
        }
        sort(vcube.begin(), vcube.end());
        for (int i = 0; i < vcube.size(); i++) {
            dp[i] = vcube[i].z;
            for (int j = i - 1; j >= 0; j--) {
                if (okup(vcube[i], vcube[j]))
                    dp[i] = max(dp[i], dp[j] + vcube[i].z); 
            }
        }
        debug(dp);
        cout << "Case " << rd++ << ": maximum height = ";
        cout << *max_element(dp.begin(), dp.end()) << "\n";
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