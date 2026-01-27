#include <bits/stdc++.h>
#include <deque>
using namespace std;
/*









*/





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
int n, q[5] ,Q;
vector<vector<string>> pro;
deque<int> proc;
queue<int> bproc;
map<char, int> vib;
int _lock = -1;
void run(int id) {
    proc.pop_front();
    int Qq = Q;
    string cmd;

    while (Qq > 0) {
        if (pro[id].size() <= 0) return;
        cmd = pro[id].back();
        
        debug(id, cmd);
        if (cmd[2] == '=') { // =
            Qq -= q[0];
            vib[cmd[0]] = stoi(cmd.substr(4, cmd.size() - 4));
        } else if (cmd[0] == 'p') { //print
            Qq -= q[1];
            cout << id + 1 << ": " << vib[cmd[6]] <<  "\n";
        } else if (cmd[0] == 'l') { //lock
            Qq -= q[2];
            if (_lock == -1) {
                _lock = id;
            } else {
                bproc.push(id);
                return;
            }
        } else if (cmd[0] == 'u') { //unlock
            if (_lock == id) {
                _lock = -1;
                if (!bproc.empty()) {
                    proc.push_front(bproc.front());
                    debug(bproc.front());
                    bproc.pop();
                }
            }
            Qq -= q[3];
        } else if (cmd[0] == 'e') { // end
            Qq -= q[4];
            pro[id].pop_back();
            return;
        }
        pro[id].pop_back();

    }
    proc.push_back(id);
}
/*
a = 4
print a
lock
b = 9
print b
unlock
print b
*/
void solve() {
    cin >> n;
    for (int i = 0; i < 5; i++) {
        cin >> q[i];
    }
    cin >> Q;
    pro.resize(n);
    cin.get();
    for (int i = 0; i < n; i++) {
        string s;
        while (getline(cin, s)) {
            pro[i].push_back(s);
            if (s == "end") break;
        }
        reverse(pro[i].begin(),pro[i].end()); 
    }
    for (int i = 0; i < n; i++) {
        proc.push_back(i);
    }
    while (!proc.empty()) {
        run(proc.front());
    }
    
}
int main() {
    // srand(time(0));
#ifndef LOCAL
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
#endif
    /*  vector<vector<string>> pro;
        deque<int> proc;
        queue<int> bproc;
        map<char, int> vib;*/
    
    int T = 1;
    cin >> T;
    while(T--) {
        pro.clear();
        proc.clear();
        while(!bproc.empty()) bproc.pop();
        vib.clear();
        solve();
        if(T >= 1) cout << "\n";
    }
    return 0;
}