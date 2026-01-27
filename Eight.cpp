#include <cstring>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <memory>
#include <map>
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
int a[9];
int at[9];
int vis[362885];
int pre[362885];
char prec[362885];
int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
//362879
int get_cantor(int an[]) {
    int ans = 0;
    for (int i = 0; i < 9; i++) {
        int count = 0;
        for (int j = i + 1; j < 9; j++) {
            count += (int)(an[i] > an[j]);
        }
        ans += (count * fac[8 - i]);
    }
    return ans;
}
void rev_cantor(int an[], int x, int &ax) {
    vector<int> nums;
    for (int i = 1; i <= 9; i++) {
        nums.push_back(i);
    }
    for (int i = 0; i < 9; i++) {
        int q = x / fac[8 - i];
        x %= fac[8 - i];
        an[i] = nums[q];
        if (an[i] == 9) ax = i;
        nums.erase(nums.begin() + q);
    }
}
void bfs() {
    
    int initc = 0;
    queue<int> qu;
    qu.push(initc);
    vis[initc] = 1;
    pre[initc] = -1;
    prec[initc] = '#';

    while (!qu.empty()) {
        int nc = qu.front();
        qu.pop();
        int ax;
        rev_cantor(at, nc, ax);
        auto opat = [&](char c) {
            int nnc = get_cantor(at);
            if (vis[nnc] == 0) {
                qu.push(nnc);
                vis[nnc] = 1;
                pre[nnc] = nc;
                prec[nnc] = c;
            }
        };
        if (ax % 3 < 2) {
            swap(at[ax], at[ax + 1]);
            opat('r');
            swap(at[ax], at[ax + 1]);
        }
        if (ax + 3 < 9) {
            swap(at[ax], at[ax + 3]);
            opat('d');
            swap(at[ax], at[ax + 3]);
        }
        if (ax % 3 > 0) {
            swap(at[ax], at[ax - 1]);
            opat('l');
            swap(at[ax], at[ax - 1]);
        }
        if (ax - 3 >= 0) {
            swap(at[ax], at[ax - 3]);
            opat('u');
            swap(at[ax], at[ax - 3]);
        }
        
        
        
        
        
    }
    
    
}
void solve() {
    bfs();
    char c;
    while (cin >> c) {
        if (c == 'x') {
            a[0] = 9;
        } else {
            a[0] = c - '0';
        }
        for (int i = 1; i < 9; i++) {
            cin >> c;
            if (c == 'x') {
                a[i] = 9;
            } else {
                a[i] = c - '0';
            }
        }
       
        int nc = get_cantor(a);
        debug(a[0]);
        if(!vis[nc]) {
            cout << "unsolvable\n";
            continue;
        }
        int printpre = nc;
        queue<char> st;
        while(pre[printpre] != -1) {
            st.push(prec[printpre]);
            printpre = pre[printpre];
        }
        map<char,char> dic;
        dic['u'] = 'd';
        dic['r'] = 'l';
        dic['d'] = 'u';
        dic['l'] = 'r';
        while(!st.empty()) {
            cout << dic[st.front()];
            st.pop();
        }
        cout << '\n';
    }
   
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    solve();
    return 0;
}