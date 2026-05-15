/*
${title}
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
*/
#include <algorithm>
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
#define endl '\n'
struct Student{
    string name;
    int yw;
    int math;
};
void justdoit() {
    int n, k;
    cin >> n >> k;
    vector<Student> a(n);
    for (auto &e : a) {
        cin >> e.name >> e.yw >> e.math;
    }
    sort(all(a), [&](const Student &a, const Student &b) {
        if (k == 1) {
            return (a.yw == b.yw) ? (a.name < b.name) : (a.yw > b.yw);
        } else {
            return (a.math == b.math) ? (a.name < b.name) : (a.math > b.math);
        }
    });
    for (auto &e : a) {
        cout << e.name << " " << e.yw << " " << e.math << endl;
    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    justdoit();
    return 0;
}