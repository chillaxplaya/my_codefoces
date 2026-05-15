/*
${title}
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
*/
#include <bits/stdc++.h>
#include <iterator>
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
char *nums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void justdoit() {
    string n;
    cin >> n;
    string num(2000, '0');
    for (auto &e : n) {
        int a = e - '0', idx = 0;
        while(a > 0) {
            num[idx] += a;
            a = 0;
            if (num[idx] > '9') {
                a = 1;
                num[idx] -= 10;
                idx++;
            }
        }
    }
    reverse(all(num));
    size_t l = num.find_first_not_of('0');
    if (l == string::npos) {
        cout << "zero";
        return;
    }
    string ans = num.substr(l, num.size() - l);
    debug(num);
    debug(ans);
    for (int i = 0 ; i < ans.size(); i++) {
        if (i) cout << " ";
        cout << nums[ans[i] - '0'];
    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    justdoit();
    return 0;
}