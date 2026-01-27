#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl
#define DEBUG_ARR(a, n) cerr << #a << " = ["; for(int i=0;i<(n);i++) cerr << (a)[i] << (i+1<(n)?", ":""); cerr << "]\n"

#define all(x) (x).begin(), (x).end()
#define ll long long

struct node {
    node *pre,*nex;
    char c;
    node() : pre(nullptr), nex(nullptr), c('#') {}
    node(node *pree, node *nexx, char cc) : pre(pree), nex(nexx), c(cc) {}
};
void printnode(node *head) {
    node *t = head;
    if(head->nex != nullptr) {
        t = head->nex;
    }
    while(t) {
        cout << t->c;
        // cout << "[" << t << "]" ;
        t = t->nex;
    }
    cout << endl;
}
void solve() {
    node *head = new node();
    node *pos = head;
    int n;
    string op;
    char c;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> op;
        if(op == "ADD") {
            cin >> c;
            if(pos->nex == nullptr) {
                node *tnode = new node(pos, nullptr, c);
                pos->nex = tnode;
                pos = tnode;
            } else {
                node *tnode = new node(pos, pos->nex, c);
                pos->nex->pre = tnode;
                pos->nex = tnode;
                pos = tnode;
            }
        } else if (op == "LEFT") {
            if(pos->pre != nullptr) pos = pos->pre; 
        } else if (op == "RIGHT") {
            if(pos->nex != nullptr) pos = pos->nex;
        }
    }
    printnode(head);
    
}
void solve1() {
    stack<char> l;
    stack<char> r;
    int n;
    string op;
    char c;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> op;
        if(op == "ADD") {
            cin >> c;
            l.push(c);
        } else if (op == "RIGHT") {
            if(!r.empty()) {
                char cc = r.top();
                r.pop();
                l.push(cc);
            }
        } else if (op == "LEFT") {
            if(!l.empty()) {
                char cc = l.top();
                l.pop();
                r.push(cc);
            }
        }
    }
    while(!l.empty()) {
        char cc = l.top();
        l.pop();
        r.push(cc);
    }
    while(!r.empty()) {
        char cc = r.top();
        r.pop();
        cout << cc;
    }

}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve1();
    return 0;
}