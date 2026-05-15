/*
奇偶递归
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-11 15:49:23
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
bool isEven(int x); //预定义
bool isOdd(int x); //预定义
bool isOdd(int x) {
    if (x == 0) return false;
    if (x == 1) return true;
    return isEven(x - 1);
}

bool isEven(int x) {
    if (x == 0) return true;
    if (x == 1) return false;
    return isOdd(x - 1);
}
void justdoit() {
    int x;
    cin >> x;
    if (isOdd(x)) {
        cout << "Odd";
    } else {
        cout << "Even";
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