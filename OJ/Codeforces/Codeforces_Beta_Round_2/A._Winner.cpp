/*
A. Winner
Time Limit: 1000ms Memory Limit: 64MB
URL: https://codeforces.com/problemset/problem/2/A
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
struct People{
    string name;
    int score;
    int time;
    People() {}
    People(string _name, int _score, int _time) : name(_name), score(_score), time(_time) {}
};
int idx = 0;
unordered_map<string, int> dic;
void justdoit() {
    int n, score;
    string name;
    cin >> n;
    debug(n);
    vector<People> rank;
    rep(i, n) {
        cin >> name >> score;
        if (dic.count(name)) {
            rank[dic[name]].score += score;
            rank[dic[name]].time = i;
        } else {
            dic[name] = rank.size();
            rank.push_back(People(name, score, i));
        }
        debug(name, rank[dic[name]].time, rank[dic[name]].score);
    }
    sort(all(rank), [&](const People &a, const People &b) {
        if (a.score == b.score) return a.time > b.time;
        return a.score < b.score;
    });
    debug(rank.size());
    cout << rank.back().name << "\n";
}
void justdoit1() {
    vector<pair<string, ll>> ops;
    unordered_map<string, ll> total;
    unordered_map<string, ll> prec;
    int n;
    cin >> n;
    ops.resize(n);
    for (auto &[a, b] : ops) {
        cin >> a >> b;
        if (total.count(a)) {
            total[a] += b;
        } else {
            total[a] = b;
        }
    }
    int maxscore = 0;
    for (auto &e : total) {
        if (e.second > maxscore) {
            maxscore = e.second;
        }
    }
    for (auto &[a, b] : ops) {
        if (prec.count(a)) {
            prec[a] += b;
        } else {
            prec[a] = b;
        }
        if (prec[a] >= maxscore && total[a] == maxscore) {
            cout << a << "\n";
            return;
        }
    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        justdoit1();
    return 0;
}