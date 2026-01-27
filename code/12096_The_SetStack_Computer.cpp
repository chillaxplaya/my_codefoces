//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3248



#include <bits/stdc++.h>
#include <vector>
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
map<set<int>, int> setId;
vector<set<int>> setCache;
int _index = 0;
int getId(const set<int> &val) {
    if(setId.count(val)) { return setId[val]; }
    setCache.push_back(val);
    return setId[val] = (_index++);
}
void initset() {
    setId.clear();
    setCache.clear();
    _index = 0;
}
void solve() {
    int n;
    cin >> n;
    initset();
    string cmd;
    stack<int> st;
    while (n--) {
        cin >> cmd;
        switch (cmd[0]) {
            case 'P' : {
                st.push(getId(set<int>()));
                break;
            }
            case 'D' : {
                st.push(st.top());
                break;
            }
            case 'A' : {
                int first_ = st.top();st.pop();
                int second_ = st.top();st.pop();
                set<int> newset = setCache[second_];
                newset.insert(getId(setCache[first_]));
                st.push(getId(newset));
                break;
            }
            case 'U' : {
                int first_ = st.top();st.pop();
                int second_ = st.top();st.pop();
                set<int> newset = setCache[first_];
                newset.insert(setCache[second_].begin(), setCache[second_].end());
                st.push(getId(newset));
                break;
            }
            case 'I' : {
                int first_ = st.top();st.pop();
                int second_ = st.top();st.pop();
                set<int> newset;
                for (auto e : setCache[first_]) {
                    if(setCache[second_].count(e)) { newset.insert(e); }
                }
                st.push(getId(newset));
                break;
            }
        }
        cout << setCache[st.top()].size() << endl;
    }
    cout << "***" << endl;
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}