#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
map<int, int> ini_sqt() {
    map<int, int> sqt;
    for(int i = 1; i < 1005; i++) {
        sqt.insert({i * i, i});
    }
    return sqt;
}
bool is_f(int a, int b, int n) {
    for(int i = 0; i < n; i++) {
        if((b + i) * (b + i) / 1000 != a + i) {
            return false;
        }
    }
    return true;
}
void solve() {
    int n, a;
    cin >> n >> a;
    bool flag = false;
    for(int i = 0; i <= a; i++) {
        for(int j = 30; j < 1010; j++) {
            if(is_f(i, j, n)) {
                // cout << i << " " << j << endl;
                printf("%d %d\n", i, j);
                flag = true;
            }
        }
    }
    if(!flag) {
        // cout << "No Solution." << endl;
        printf("No Solution.\n");
    }
}
int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    // cout << is_f(85,293,3) << endl;;
    while(T--) solve();
    return 0;
}