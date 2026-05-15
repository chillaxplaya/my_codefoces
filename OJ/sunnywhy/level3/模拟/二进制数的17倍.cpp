/*
二进制数的17倍
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-05 18:19:07
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
string add(string a, string b) {
    reverse(all(a));
    reverse(all(b));
    string c;
    int al = a.length();
    int bl = b.length();
    int i = 0;
    int flag = 0;
    while(i < al || i < bl) {
        int ga = 0;
        int gb = 0;
        if (i < al) {
            ga = a[i] - '0';
        }
        if (i < bl) {
            gb = b[i] - '0';
        }
        int x = ga + gb + flag;
        flag = (x & 2) ? 1 : 0;
        x = x & 1;
        c.push_back((char)(x + '0'));
        debug(c);
        i++;
    }
    if (flag) c.push_back('1');
    reverse(all(c));
    return c;
}
void justdoit() {
    string n;
    cin >> n;
    string a = n;
    string b = n + "0000";
    cout << add(a, b);
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