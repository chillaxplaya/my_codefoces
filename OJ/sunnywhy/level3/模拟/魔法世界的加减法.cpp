/*
魔法世界的加减法
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-06 15:15:55
*/
#include <bits/stdc++.h>
#include <regex>
#include <string>
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
string minu(string a, string b) {
    string c;
    while(a.size() < b.size()) {
        a = '0' + a;
    }
    while(b.size() < a.size()) {
        b = '0' + b;
    }
    debug(a, b, "1");
    for (int i = 0; i < b.size(); i++) {
        c.push_back(abs(a[i] - b[i]) + '0');
    }
    return c;
}
string add(string a, string b) {
    int cnta = 0;
    for (auto &e : a) {
        cnta += e - '0';
    }
    int cntb = 0;
    for (auto &e : b) {
        cntb += e - '0';
    }
    return to_string(cnta * cntb);
}
void justdoit() {
    string s;
    cin >> s;
    string a;
    int validx = 0;
    while (validx < s.size() && s[validx] != '-' && s[validx] != '+') {
        a += s[validx++];
    }
    int n = 0;
    vector<int> opidx;
    opidx.push_back(-1);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-' || s[i] == '+') {
            opidx.push_back(i);
        }
    }
    //759909671250106510510046-923385016033133721858528436184742646697954978166+12517789694479374237407864352268849847-69219942460194367877645640259313664144993+230175083486026+403758267004640414203572582631671-202293842207964823+71289002202760309695470802565728383789167243050

    opidx.push_back(s.size());
    a = s.substr(opidx[0] + 1, opidx[1] - opidx[0] - 1);
    while (a.size() > 1 && a[0] == '0') a.erase(a.begin());

    for (int i = 1; i < opidx.size() - 1; i++) {
        string b = s.substr(opidx[i] + 1, opidx[i + 1] - opidx[i] - 1);
        while (b.size() > 1 && b[0] == '0') b.erase(b.begin()); 
        if (s[opidx[i]] == '-') {
            debug(a, b);
            a = minu(a, b);
            debug(a);
        } else {
            debug(a, b);
            a = add(a, b);
            debug(a);
        }
        while (a.size() > 1 && a[0] == '0') a.erase(a.begin()); 
    }
    cout << a;
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