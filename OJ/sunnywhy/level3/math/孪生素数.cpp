/*
孪生素数
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-11 12:15:49
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
int primnum[2000005];
void initPrime(vector<int> &prims) {
    for (int i = 2; i * i <= 2000000; i++) {
        if (!primnum[i]) {
            for (int j = i * i; j < 2000000; j += i) {
                primnum[j] = 1;
            }
        }
    }
    for (int i = 2; i <= 200000; i++) {
        if (!primnum[i]) {
            prims.push_back(i);
        }
    }
}
void justdoit() {
    int n;
    cin >> n;
    vector<int> prims;
    initPrime(prims);
    for (int i = 1; i < prims.size(); i++) {
        if (prims[i] - prims[i - 1] == 2) {
            n--;
            if (n == 0) {
                cout << prims[i - 1] << " " << prims[i] ;
                return;
            }
        }
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