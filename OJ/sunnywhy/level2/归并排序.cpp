/*
归并排序
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-03 10:56:26
*/
#include <bits/stdc++.h>
#include <algorithm>
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
#define MAXN  1005

int merge(int l, int mid, int r, int *a, int *temp) {
    int i = l, j = mid;
    int idx = 0;
    
    while (i < mid && j < r) {
        if (a[i] < a[j]) {
            temp[idx++] = a[i++];
        } else {
            temp[idx++] = a[j++];
        }
    }
    while(i < mid) {
        temp[idx++] = a[i++];
    }
    while(j < r) {
        temp[idx++] = a[j++];
    }
    for (int i = 0; i < idx; i++) {
        a[i + l] = temp[i];
    }
    return r - l;
}
int mergesort(int l, int r, int *a, int *temp) {
    if (r - l == 1) return 0;
    int mid = l + (r - l) / 2;
    mergesort(l, mid, a, temp);
    mergesort(mid, r, a, temp);
    merge(l, mid, r, a, temp);
    return 0;
}
int a[MAXN];
int temp[MAXN];
void justdoit() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergesort(0, n, a, temp);
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << a[i];
    }
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