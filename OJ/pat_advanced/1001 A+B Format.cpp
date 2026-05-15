/*
${title}
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define INF 0x3f3f3f3f

#define debug_arr(a, n)                 \
    cerr << "[" << #a << "] = {";       \
    for (int i = 0; i < (n); i++)       \
        cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

void justdoit() {
    int a, b;
    cin >> a >> b;
    a += b;
    vector<int> res;
    while(a / 1000) {
        res.push_back(abs(a % 1000));
        a /= 1000;
    }
    reverse(all(res));
    
    cout << a;

    for (auto &e : res) {

        cout << ",";
        if (e < 10) {
            cout << "00";
        } else if (e < 100) {
            cout << "0";
        }
        cout << e;
    }
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