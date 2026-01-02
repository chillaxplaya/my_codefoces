#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define ll long long
int n, k;
string s[10];
void solve() {
    
}
int sum = 0;
int c[10];
void dfs(int h) {
    if(h == k) {
        sum++;
        return;
    }
    for(int i = h; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(c[j]) continue;
            if(s[i][j] == '#'){
                c[j] = 1;
                dfs(h+1);
                c[j] = 0;
                
            }
        }
    }
}
int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    
    while(1) {
        cin >> n >> k;
        sum = 0;
        if (n == -1 && k == -1) {
            return 0;
        }
        for(int i = 0; i < n; i++) {
            c[i] = 0;
            cin >> s[i];
        }
        dfs(0);
        cout << sum << endl;
    }
    
    return 0;
}