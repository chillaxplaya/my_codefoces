    #include <bits/stdc++.h>
    using namespace std;

    #define DEBUG(x) cerr << #x << " = " << x << endl
    #define all(x) (x).begin(), (x).end()
    #define ll long long
    void dfs(int n, int h) {
        if(n == 0) return ;
        dfs(n/10, h + 1);
        if(((h + 1) % 3 )== 0 && n >= 10) {
            cout << ',';
        }
        cout << n % 10;
    }
    void solve() {
        int a,b;
        cin >> a >> b;
        int c = a + b;
        if(c < 0) {
            cout << "-";
            c = -c;
        }
        if(c < 1000) {
            cout << c ;
            return ;
        }
        dfs(c,0);
        
    }
    int main() {
        srand(time(0));
        ios::sync_with_stdio(0);
        cout.tie(0), cin.tie(0);
        
        solve();


        return 0;
    }