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
char graph[20][20];
int graph_i[20][20];
int n, m;
void print_row(int i, int j) {
    while(j < m && graph[i][j] != '*') {
        putchar(graph[i][j]);
        j++;
    }
}
void print_col(int i, int j) {
    while(i < n && graph[i][j] != '*') {
        putchar(graph[i][j]);
        i++;
    }
}
void solve() {
    int tcase = 1;
    while (scanf("%d", &n) && n) {
        scanf("%d", &m);
        int index = 1;
        for (int i = 0; i < n; i++) {
            scanf("%s", graph[i]);
            for (int j = 0; j < m; j++) {
                if (graph[i][j] != '*') {
                    
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] != '*' && (j == 0 || graph[i][j - 1] == '*')) {
                    graph_i[i][j] = index++;
                    continue;
                }
                if (graph[i][j] != '*' && (i == 0 || graph[i - 1][j] == '*')) {
                    graph_i[i][j] = index++;
                    continue;
                }
            }
        }
        //Across
        if ( tcase > 1 ) {
            putchar('\n');
        }
        printf("puzzle #%d:\n", tcase++);
        printf("Across\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] != '*' && (j == 0 || graph[i][j - 1] == '*')) {
                    printf("%3d.", graph_i[i][j]);
                    print_row(i, j);
                    putchar('\n');
                }
            }
        }
        printf("Down\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] != '*' && (i == 0 || graph[i - 1][j] == '*')) {
                    printf("%3d.", graph_i[i][j]);
                    print_col(i, j);
                    putchar('\n');
                }
            }
        }
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