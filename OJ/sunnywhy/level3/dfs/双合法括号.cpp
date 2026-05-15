/*
双合法括号
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-12 12:08:40
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
int n;
void dfs(string s, string st, int left, int right) {
    if (left == right && left == n) {
        cout << s << endl;
    }
    if (left < n) {
        dfs(s + "[", st + "[", left + 1, right);
    }

    if (right < left) {
        if (st.back() == '[') {
            st.pop_back();
            dfs(s + "]", st, left, right + 1);
            st.push_back('[');
        }
    }
    if (left < n) {
        dfs(s + "{", st + "{", left + 1, right);
    }
    if (right < left) {
        if (st.back() == '{') {
            st.pop_back();
            dfs(s + "}", st, left, right + 1);
            st.push_back('{');
        }
    }
    
}
void justdoit() {
    cin >> n;
    n /= 2;
    dfs("", "", 0, 0);
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