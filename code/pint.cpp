#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
string a[105];
int m[105][105];
int h, w;
void linet(int h1, int w1) {
    for(int j = w1; j < w; j++) {
        if(m[h1][j] == 1 || m[h1][j] == 3) {
            m[h1][j] -= 1;
            continue;
        }
        break;
    }
}
void colt(int h1, int w1) {
    for(int j = h1; j < h; j++) {
        if(m[j][w1] == 2 || m[j][w1] == 3) {
            m[j][w1] -= 2;
            continue;
        }
        break;
    }
}
void solve() {

    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(a[i][j] == 'R') {
                m[i][j] = 1;
            }
            if(a[i][j] == 'B') {
                m[i][j] = 2;
            }
            if(a[i][j] == 'G') {
                m[i][j] = 3;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(m[i][j] == 1) {
                linet(i, j);
                ans++;
            } else if (m[i][j] == 2) {
                colt(i, j);
                ans++;
            } else if (m[i][j] == 3) {
                linet(i, j);
                colt(i, j);
                ans += 2;
            }

        }
    }
    cout << ans <<endl;
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