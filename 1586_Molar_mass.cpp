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
double C = 12.01;
double H = 1.008;
double O = 16.00;
double N = 14.01;
int getNum(string s, int index) {
    int num = 0;
    while (index < s.size() && s[index] >= '1' && s[index] <= '9') {
        num *= 10;
        num += (s[index] - '0');
        index++;
    }
    return num;
}
void solve() {
    string s;
    cin >> s;
    int l = s.size();
    double sum = 0;
    for (int i = 0; i < l; i++) {
        double add;
        if (s[i] == 'C') {
            add = C;
        } else if (s[i] == 'H') {
            add = H;
        } else if (s[i] == 'O') {
            add = O;
        } else if (s[i] == 'N') {
            add = N;
        } else {
            continue;
        }
        if (i + 1 == l || !(s[i + 1] >= '1' && s[i + 1] <= '9')) {
            sum += add;
            debug(add);
        } else {
            sum += (add * getNum(s, i + 1));
            debug(add * getNum(s, i + 1));
        }
    }
    printf("%.3lf\n", sum);
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