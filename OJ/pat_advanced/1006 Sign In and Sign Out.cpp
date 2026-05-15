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
#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

void justdoit() {
    int n;
    cin >> n;
    string begin_name;
    string end_name;
    string name;
    int begintime = 0x3f3f3f3f;
    int endtime = -1;
    rep(i, n) {
        string l, r;
        replace(all(l), ':', ' ');
        replace(all(r), ':', ' ');
        cin >> name >> l >> r;
        int h, m, s;
        {
            stringstream ss(l);
            ss >> h >> m >> s;
            h = h * 60 * 60 + m * 60 + s;
            if (h < begintime) {
                begintime = h;
                begin_name = name;
            }
        }
        
        {
            stringstream ss(r);
            ss >> h >> m >> s;
            h = h * 60 * 60 + m * 60 + s;
            if (h > endtime) {
                endtime = h;
                end_name = name;
            }
        }
    }
    cout << begin_name << " " << end_name;
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    justdoit();
    return 0;
}