/*
单峰序列
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-02 17:44:29
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
#define endl '\n'
int n;
vector<int> a;
int cnt = 0;
int findh(int l, int r) {
    while(l < r) {
        int mid = l + (r - l) / 2;
        if (mid > 0 && a[mid - 1] < a[mid] && mid < n - 1 && a[mid + 1] < a[mid]) {
            return mid;
        } else if ((mid > 0 && a[mid - 1] > a[mid] && mid < n - 1 && a[mid + 1] < a[mid]) || mid == a.size() - 1) {
            r = mid;
        } else if ((mid > 0 && a[mid - 1] < a[mid] && mid < n - 1 && a[mid + 1] > a[mid]) || mid == 0) {
            l = mid + 1;
        }
        if (cnt++ > 100) break; 
        debug(l, r, mid);
    }
    return l;
}
void justdoit() {
    cin >> n;
    a.resize(n);
    for (auto &e : a) {
        cin >> e;
    }
    cout << findh(0, n);
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        justdoit();
    return 0;
}