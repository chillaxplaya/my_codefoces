/*
${title}
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n)                 \
    cerr << "[" << #a << "] = {";       \
    for (int i = 0; i < (n); i++)       \
        cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
int getSum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * @param head: 链表的头节点
 */
void adjust231List(ListNode* head) {
    ListNode* last = head;
    while (last && last->next && last->next->next && last->next->next->next) {
        ListNode* p1 = last->next;
        ListNode* p2 = p1->next;
        ListNode* p3 = p2->next;
        p1->next = p3->next;
        p3->next = p1;
        last->next = p2;

        last = p1;
    }
}
void compactList(ListNode* head) {
    ListNode* last = head;
    if (!last) return;
    while (last && last->next) {
        ListNode* p1 = last->next;
        if (p1->val == last->val) {
            last->next = p1->next;
            delete p1;
            
        } else {
            last = last->next;
        }
    }
}
void justdoit() {
    cout << INT_MAX;
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        justdoit();
    return 0;
}