/*
A. Friendly Numbers
Time Limit: 1000ms Memory Limit: 256MB
URL: https://codeforces.com/contest/2197/problem/A
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
int getsum(int x) {
    int sum = 0;
    while(x) {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}
void justdoit() {
    int x;
    int ans = 0;
    cin >> x;
    for (int i = x + 1; ;i++) {
        int t = i - getsum(i);
        if (t == x) {
            ans++;
        } else if (t > x) {
            break;
        }
            
    }
    cout << ans << '\n';
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        justdoit();
    return 0;
}