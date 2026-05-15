/*
C. 模式替换
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-04 19:52:26
*/
#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
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
int uper[205];
void justdoit() {
    int n;
    string s;
    cin >> n;
    cin.get();
    unordered_map<string, char> dic3;
    unordered_map<string, char> dic2;
    dic3["and"] = '&';dic3["end"] = '&';
    dic3["one"] = '1';dic3["won"] = '1';
    dic3["too"] = '2';dic3["two"] = '2';
    dic3["bcd"] = 'a';dic3["xyz"] = 'b';
    dic3["pqr"] = 'c';dic3["mno"] = 'd';
    dic2["at"] = '@';dic2["an"] = '@';
    dic2["to"] = '2';dic2["bc"] = 'a';
    dic2["xy"] = 'b';dic2["pq"] = 'c';
    dic2["mn"] = 'd';
    string _template = "atanandendonewontwobcdxyzpqrmno";
    rep(i, n) {
        getline(cin, s);
        for (int j = 0; j < s.size(); j++) {
            uper[j] = 0;
            if (s[j] >= 'A' && s[j] <= 'Z') {
                uper[j] = 1;
                s[j] = s[j] - 'A' + 'a';
            }
        }
        for (int j = 0; j < s.size(); ) {
            if (_template.find(s[j]) == string::npos) {
                if (uper[j]) cout <<(char)(s[j] - 'a' + 'A');
                else cout << s[j];
                j++;
                continue;
            }
            if (j < s.size() - 2) {
                string t = s.substr(j, 3);
                if (dic3.count(t)) {
                    if (uper[j] && dic3[t] >= 'a' && dic3[t] <= 'z') {
                        cout << (char)(dic3[t] - 'a' + 'A');
                    } else {
                        cout << dic3[t];
                    }
                    j += 3;
                    continue;
                }
            }
            if (j < s.size() - 1) {
                string t = s.substr(j, 2);
                if (dic2.count(t)) {
                    if (uper[j] && dic2[t] >= 'a' && dic2[t] <= 'z') {
                        cout << (char)(dic2[t] - 'a' + 'A');
                    } else {
                        cout << dic2[t];
                    }
                    j += 2;
                    continue;
                }
            }
            if (uper[j]) cout <<(char)(s[j] - 'a' + 'A');
            else cout << s[j];
            j++;
        }
        cout << endl;
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