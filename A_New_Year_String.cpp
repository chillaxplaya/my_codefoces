#include<bits/stdc++.h>
using namespace std;
#define DEBUG(x) cerr << #x << " " << x << endl
void solve() {
    int n;
    string a;
    cin >> n;
    cin >> a;
    if(a.find("2025") != string::npos) {
        if(a.find("2026") != string::npos) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    } else {
        cout << 0 << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}