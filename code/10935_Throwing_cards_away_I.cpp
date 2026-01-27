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
int getNext(int idx, vector<int> &a, int n) {
    for (int i = 1; i < n; i++) {
        if(a[(idx + i) % n] == 1) {
            return (idx + i) % n;
        }
    }
    return -1;
}
void solve() {  
    int n;
    while (cin >> n && n) {
        vector<int> a(n, 1);
        int index = 0;
        int t = n - 2;
        if (t == -1) {
            t = 0;
            cout << "Discarded cards:";
        } else {
            cout << "Discarded cards: 1";
            a[0] = 0;
        }
        
        
        index = 2;
        
        while (t--) {
            cout << ", " << index + 1;
            a[index] = 0;
            index = getNext(index, a, n);
            index = getNext(index, a, n);
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                cout << "Remaining card: " << i + 1 << endl;
                break;
            }
        }
    }
    
}
void solvequeue() {
    int n;
    while (cin >> n && n) {
        queue<int> qu;
        for (int i = 1; i <= n; i++) {
            qu.push(i);
        }
        int t = n - 1;
        cout << "Discarded cards:";
        bool firs = true;
        while (t--) {
            int i = qu.front();
            if (!firs) cout << ',';
            firs = false;
            cout << " " << i;
            qu.pop();
            qu.push(qu.front());
            qu.pop();
        }
        cout << "\n";
        cout << "Remaining card: " << qu.front() << "\n";
    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}