#include <bits/stdc++.h>
#include <cstring>
#include <deque>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
int fac[] = {1, 1, 2, 6, 24, 24 * 5, 24 * 5 * 6, 24 * 5 * 6 * 7, 24 * 5 * 6 * 7 * 8  };
#define debug_arr(a, n) \
    cerr << "[" << #a << "] = {"; \
    for (int i = 0; i < (n); i++) cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

int get_cantor(const string &s) {
    int res = 0;
    for (int i = 0; i < 9; i++) {
        int cnt = 0;
        for (int j = i + 1; j < 9; j++) {
            if(s[j] < s[i]) cnt++;
        }
        res += (cnt * fac[8 - i]);
    }
    return res;
}
string rev_cantor(int x, int &xi) {
    
    string res = "";
    vector<char> nums;
    for (int i = 1; i < 9; i++) {
        nums.push_back('0' + i);
    }
    nums.push_back('X');
    for (int i = 0; i < 9; i++) {
        int q = x / fac[8 - i];
        x %= fac[8 - i];
        res.push_back(nums[q]);
        if (nums[q] == 'X') xi = i;
        nums.erase(nums.begin() + q);
    }
    return res;
}
string rev_cantor(int x) {
    
    string res = "";
    vector<char> nums;
    for (int i = 1; i < 9; i++) {
        nums.push_back('0' + i);
    }
    nums.push_back('X');
    for (int i = 0; i < 9; i++) {
        int q = x / fac[8 - i];
        x %= fac[8 - i];
        res.push_back(nums[q]);
        nums.erase(nums.begin() + q);
    }
    return res;
}
#define all(x) (x).begin(), (x).end()
#define ll long long
int rd = 0;
int pre[9][362885];
int vis[9][362885];
char prec[9][362885];
stack<char> st;
void bfs(int start, int kind) {
    debug(start, kind);
    queue<int> qu;
    qu.push(start);
    pre[kind][start] = -1;
    vis[kind][start] = 1;
    bool findres = false;
    while (!qu.empty()) {
        int nc = qu.front();
        qu.pop();
        int nx;
        
        string ns = rev_cantor(nc, nx);
        auto op = [&](const int nx1,const char c) {
            swap(ns[nx], ns[nx1]);

            int ncc = get_cantor(ns);
            if (!vis[kind][ncc]) {
                vis[kind][ncc] = 1;
                pre[kind][ncc] = nc;
                prec[kind][ncc] = c;
                qu.push(ncc);
            }
            swap(ns[nx], ns[nx1]);
        };
        if (nx + 3 < 9) {
            op(nx + 3, 'd');
        }
        if (nx % 3 > 0) {
            op(nx - 1, 'l');
        }
        if (nx % 3 < 2) {
            op(nx + 1, 'r');
        }
        if (nx - 3 >= 0) {
            op(nx - 3, 'u');
        }
        
    }
    

}
void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    string target = "12345678";
    unordered_map<char, char> mp;
    int idx = 0;
    for (char c : s1) {
        if (c == 'X') continue;
        if (!mp.count(c)) {
            mp[c] = target[idx++];
        }
    }
    mp['X'] = 'X';
    for (char &c : s1) {
        c = mp[c];
    }

    for (char &c : s2) {
        c = mp[c];
    }

    int startc = get_cantor(s1);
    int targetc = get_cantor(s2);
    int kind;
    string ts = rev_cantor(startc, kind);
    debug(s1, s2);
    debug("lqw");
    int prei = targetc;
    while(pre[kind][prei] != -1) {
        st.push(prec[kind][prei]);
        prei = pre[kind][prei];
    }
    cout << "Case " << ++rd << ": " << st.size() << '\n';
    
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << "\n";
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    string target[9];
    memset(vis, 0, sizeof(vis));
    target[0] = "X12345678";
    target[1] = "1X2345678";
    target[2] = "12X345678";
    target[3] = "123X45678";
    target[4] = "1234X5678";
    target[5] = "12345X678";
    target[6] = "123456X78";
    target[7] = "1234567X8";
    target[8] = "12345678X";
    for (int i = 0; i < 9; i++) {
        int targetc = get_cantor(target[i]);
        bfs(targetc, i);
    }
    
    
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}