/*
B. 进制素数概率
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-14 19:33:12
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
int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}
bool isPrime(ll x) {
    if (x == 1 || x == 0) return false;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int get16(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return c - 'A' + 10;
}
void justdoit() {
    string s;
    cin >> s;
    int n2 = 1;
    int n8 = 1;
    int n10 = 1;
    int n16 = 1;
    while(!s.empty() && s[0] == '0') {
        s.erase(s.begin());
    }
    for (auto &e : s) {
        if ((e >= '2' && e <= '9') || (e >= 'A' && e <= 'F')) {
            n2 = 0;
        }
        if ((e >= '8' && e <= '9') || (e >= 'A' && e <= 'F')) {
            n8 = 0;
        }
        if ((e >= 'A' && e <= 'F')) {
            n10 = 0;
        }
    }
    int n2s = 0;
    if (n2) {
        ll num = 0;
        ll pre = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            num += (s[i] - '0') * pre;
            pre *= 2;
        }
        debug(num);
        if (isPrime(num)) n2s = 1;
    }
    int n8s = 0;
    if (n8) {
        ll num = 0;
        ll pre = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            num += (s[i] - '0') * pre;
            pre *= 8;
        }
        debug(num);
        if (isPrime(num)) n8s = 1;
    }
    int n10s = 0;
    if (n10) {
        ll num = 0;
        ll pre = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            num += (s[i] - '0') * pre;
            pre *= 10;
        }
        debug(num);
        if (isPrime(num)) n10s = 1;
    }
    int n16s = 0;
    if (n16) {
        ll num = 0;
        ll pre = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            num += get16(s[i]) * pre;
            pre *= 16;
        }
        debug(num);
        if (isPrime(num)) n16s = 1;
    }
    debug(n2, n8, n10, n16);
    debug(n2s, n8s, n10s, n16s);
    int a = n2 + n8 + n10 + n16;
    int b = n2s + n8s + n10s + n16s;
    debug(b, a);

    if (b == 0) {
        cout << "0/1";
    } else {
        int g = gcd(a, b);
        cout << b / g << "/" << a / g;
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