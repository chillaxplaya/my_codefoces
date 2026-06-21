/*
B - 459
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc459/tasks/abc459_b
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
    string s[10];
    s[2] = "abc";
    s[3] = "def";
    s[4] = "ghi";
    s[5] = "jkl";
    s[6] = "mno";
    s[7] = "pqrs";
    s[8] = "tuv";
    s[9] = "wxyz";
    int n;
    string word;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word;
        if (word.size() > 0) {
            for (int i = 2; i <= 9; i++) {
                if (s[i].find(word[0]) != string::npos) {
                    cout << i;
                    break;
                }
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