#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long
vector<int> primes;
int primev[30005];
void initPrime() {
    for (int i = 2; i < 30005; i++) {
        if (primev[i]) continue;
        for (int j = i * i; j < 30005; j += i) {
            primev[j] = 1;
        }
    }
    for (int i = 2; i < 30005; i++) {
        if (!primev[i]) {
            primes.push_back(i);
        }
    }
}
int twoFind(vector<int> &ps,int n, int d) {
    int l = 0, r = primes.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if(primes[mid] < n + d) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return primes[r];
}
void solve() {
    int d;
    cin >> d;
    int c = twoFind(primes, 1, d);
    cout << c * twoFind(primes, c, d) << endl;
}
int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    initPrime();
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}