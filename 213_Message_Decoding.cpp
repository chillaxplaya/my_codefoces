#include <bits/stdc++.h>
#include <cmath>
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
/*


001 0 1
011 000 111 
010 00 10 01 11 
011 001 111 
000


0 00 01 10 000 001 010 011 100 101 110
0  0  1  2   0   1   2   3   4   5   6
*/
char a[413];
bool iszero(string s) {
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') {
            return false;
        }
    }
    return true;
}
bool is2n1(string s) {
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0') {
            return false;
        }
    }
    return true;
}
string getcharplus(int k) {
    string t = "";
    while(k) {
        char c = getchar();
        debug(c);
        if (c == '0' || c == '1') {
            t += c;
            k--;
        }
    }
    return t;
}
int getB(string s) {
    int j = 1;
    int sum = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1') {
            sum += j;
        }
        j <<= 1;
    }
    return sum;
}
string getB(int l, int val) {
    string s = "";
    for (int i = l; i > 0; i--) {
        s += (((1 << (i - 1)) & val)) ? "1" : "0";
    }
    return s;
}
map<string, char> encode(char *s) {
    map<string, char> dic;
    int index = 0;
    for (int i = 1; ; i++) {
        for (int j = 0; j < (1 << i) - 1; j++) {
            if (s[index] == '\0' || s[index] == '\n') return dic;
            dic[getB(i, j)] = s[index++];
        }
    }
}
void solve() {
    while(fgets(a, 400, stdin)) {
        map<string, char> dic = encode(a);        
        while (true) {
            debug(321);
            string nums = getcharplus(3);
            debug(123);
            if (iszero(nums)) {
                break;
            }
            int num = getB(nums);
            debug(num);
            while (1) {
                string nextcode = getcharplus(num);
                if (is2n1(nextcode)) break;
                putchar(dic[nextcode]);
            }
        }
        char c;
        while((c = getchar()) != '\n');
        putchar('\n');
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