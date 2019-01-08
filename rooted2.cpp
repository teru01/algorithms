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
struct Node
{
    int p;
    int l;
    int r;
    int depth;
};
Node T[MAX];

void calcDepth(Node *node) {
    node->depth = T[node->p].depth + 1;
    if (node->r != NIL)
        calcDepth(&T[node->r]);
    if(node->l != NIL)
        calcDepth(&T[node->l]);
}

void print(int u) {
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].p << ", ";
    cout << "depth = " << T[u].depth << ", ";
    if (T[u].p == NIL)
    {
        cout << "root, ";
    }
    else if (T[u].l == NIL)
    {
        cout << "leaf, ";
    }
    else
    {
        cout << "internal node, ";
    }
    cout << "[";
    if(T[u].l != NIL) {
        cout << T[u].l;
        Node node = T[T[u].l];
        while(node.r != NIL) {
            cout << ", " << node.r;
            node = T[node.r];
        }
    }
    cout << "]\n";
}

int main() {
    int n, root;
    cin >> n;
    for(int i=0; i<n; i++) {
        T[i].p = T[i].l = T[i].r = NIL;
        T[i].depth = 0;
    }
    for(int i=0; i<n; i++) {
        int id, nchil;
        cin >> id;
        cin >> nchil;
        int prevchild;
        for(int j=0; j<nchil; j++) {
            int child;
            cin >> child;
            if(j == 0) {
                T[id].l = child;
            }
            T[child].p = id;
            if(j != 0) {
                T[prevchild].r = child;
            }
            prevchild = child;
        }
    }

    for(int i=0; i<n; i++) {
        if(T[i].p == NIL) root = i;
    }
    if (T[root].l != -1) {
        calcDepth(&T[T[root].l]);
    }
    for (int i = 0; i < n; i++)
    {
        print(i);
    }
}
