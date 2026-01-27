#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> timescale;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += (i*5);
        timescale.push_back(sum);
    }
    k = 240 - k;
    for(int i = 0; i < timescale.size(); i++) {
        if(k < timescale[i]) {
            cout << i << endl;
            return ;
        }
    }
    cout << n << endl;
}
int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}