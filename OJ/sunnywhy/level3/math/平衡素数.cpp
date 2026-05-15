/*
平衡素数
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-11 12:43:11
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define MAXN 20050000
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define endl '\n'
int primnum[MAXN];
vector<int> prims;
void initPrims(vector<int> &prims) {
    for (int i = 2; i * i < MAXN; i++) {
        if (!primnum[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                primnum[j] = 1;
            }
        }
    }
    for (int i = 2; i < MAXN; i++) {
        if (!primnum[i]) {
            prims.push_back(i);
        }
    }
}
map<int, int> dic;
void justdoit() {
    int x; 
    cin >> x;
    if (dic.count(x)) {
        if (dic[x] == x) {
            cout << "Yes\n";;
        } else {
            cout << "No " << dic[x] << endl;
        }
        return;
    }

    int idx = lower_bound(all(prims), x) - prims.begin();
    if (x == 2) {
        cout << "No " << 3 << endl;
        return;
    }
    for (int i = idx; ; i++) {
        if (prims[i] == (prims[i - 1] + prims[i + 1]) / 2) {
            if (prims[i] == x) {
                cout << "Yes\n";;
            } else {
                cout << "No " << prims[i] << endl;
            }
            dic[x] = prims[i];
            return;
        }
    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    initPrims(prims);
    debug(prims[1000]);
    while (T--)
        justdoit();
    return 0;
}