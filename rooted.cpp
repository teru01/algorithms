#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <complex>
#include <functional>
#include <climits>
#define NIL -1
#define MAX 100005
using namespace std;
struct Node {
    int p, l, r;
};
Node T[MAX];
int n, D[MAX];
void print(int u) {
    int i, c;
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].p << ", ";
    cout << "depth = " << D[u] << ", ";
    if(T[u].p == NIL) {
        cout << "root, ";
    } else if(T[u].l == NIL) {
        cout << "leaf, ";
    } else {
        cout << "internal node, ";
    }
    cout << "[";
    if(T[u].l != NIL) {
        cout << T[u].l;
        Node node = T[T[u].l];
        while(node.r != NIL) {
            cout << ", ";
            cout << node.r;
            node = T[node.r];
        }
    }
    cout << "]\n";
}

void rec(int r, int d) {
    D[r] = d;
    if(T[r].l != NIL) {
        rec(T[r].l, d+1);
    }
    if(T[r].r != NIL) {
        rec(T[r].r, d);
    }
}
int main() {
    int i, j, d, v, c, l, r;
    cin >> n;
    for(int i=0; i<n; i++) T[i].p = T[i].l = T[i].r = NIL;

    for(int i=0; i<n; i++) {
        cin >> v >> d;
        for(j=0; j<d; j++) {
            cin >> c;
            if(j == 0) T[v].l = c;
            else T[l].r = c;
            l = c;
            T[c].p = v;
        }
    }
    for(int i=0; i<n; i++) {
        if(T[i].p == NIL) r = i;
    }
    rec(r, 0);

    for(int i=0; i<n; i++) {
        print(i);
    }
}
