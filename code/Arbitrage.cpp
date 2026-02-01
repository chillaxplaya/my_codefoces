#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n) \
    cerr << "[" << #a << "] = {"; \
    for (int i = 0; i < (n); i++) cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";


#define all(x) (x).begin(), (x).end()
#define ll long long
int n;
int idx = 0;
map<string, int> dic;
int getId(string dl) {
    if (dic.count(dl)) return dic[dl];
    return dic[dl] = idx++;
}
int saveId(string dl) {
    if (dic.count(dl)) return dic[dl];
    return dic[dl] = idx++;
}
double rate[35][35];
int rd = 1;
bool spfa() {
    vector<double> dis(n, 1.0);
    vector<int> cnt(n, 1);
    vector<int> inQ(n, 1);
    queue<int> qu;
    for (int i = 0; i < n; i++) {
        qu.push(i);
    }
    while (!qu.empty()) {
        int x = qu.front();
        qu.pop();
        inQ[x] = 0;
        for (int i = 0; i < n; i++) {
            if (dis[i] < rate[x][i] * dis[x]) {
                dis[i] = rate[x][i] * dis[x];
                if (!inQ[i]) {
                    qu.push(i);
                    inQ[i] = 1;
                    if(++cnt[i] >= n) return true;
                    
                }
            }
        }
        
    }
    return false;
}
void solve() {
    int m;
    idx = 0;
    string d;
    dic.clear();
    memset(rate, 0 ,sizeof(rate));
    for (int i = 0; i < n; i++) {
        cin >> d;
        saveId(d);
    }
    cin >> m;
    string d1, d2;
    double rt;
    for (int i = 0; i < m; i++) {
        cin >> d1 >> rt >> d2;
        rate[getId(d1)][getId(d2)] = rt;
        debug(getId(d1));
        debug(getId(d2));
        debug(rt);
    }
    if (spfa()) cout << "Case "<< rd++ <<": " << "Yes\n";
    else cout << "Case "<< rd++ <<": " << "No\n";
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;

    // cin >> T;
    while(cin >> n && n) solve();
    return 0;
}