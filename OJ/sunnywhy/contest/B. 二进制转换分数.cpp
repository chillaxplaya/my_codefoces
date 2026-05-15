/*
B. 二进制转换分数
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-13 19:35:04
user: playa
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
typedef pair<int, int> pi;

void justdoit() {
    int n;
    cin >> n;
    vector<int> bitres;
    while (n) {
        bitres.push_back(n & 1);
        n >>= 1;
    }
    reverse(all(bitres));
    int a = 1;
    int b = 1;
    for (int i = 1; i < (int)bitres.size(); i++) {
        if (bitres[i] == 0) {
            b += a;
        } else {
            a += b;
        }
    }
    int g = gcd(a, b);
    cout << a / g << "/" << b / g << endl;
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