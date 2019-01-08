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
    int parent, left, right, depth, sibling, degree, height;
};
Node T[MAX];
void print(int u)
{
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "sibling = " << T[u].sibling << ", ";
    cout << "degree = " << T[u].degree << ", ";
    cout << "depth = " << T[u].depth << ", ";
    cout << "height = " << T[u].height << ", ";
    if (T[u].parent == NIL)
    {
        cout << "root";
    }
    else if (T[u].left == NIL && T[u].right == NIL)
    {
        cout << "leaf";
    }
    else
    {
        cout << "internal node";
    }
    cout << "\n";
}
void calcDepth(Node *node)
{
    if(node->parent == NIL){
        node->depth = 0;
    } else {
        node->depth = T[node->parent].depth + 1;
    }
    if (node->left != NIL)
        calcDepth(&T[node->left]);
    if (node->right != NIL)
        calcDepth(&T[node->right]);
}

int calcHeight(Node *node) {
    if(node->left != NIL && node->right != NIL) {
        node->height = max(calcHeight(&T[node->left]) + 1, calcHeight(&T[node->right]) + 1);
    } else if(node->left != NIL) {
        node->height = calcHeight(&T[node->left]) + 1;
    } else if(node->right != NIL) {
        node->height = calcHeight(&T[node->right]) + 1;
    } else {
        node->height = 0;
    }
    return node->height;
}

int main() {
    int n, root;
    cin >> n;
    for(int i=0; i<n; i++){
        T[i].degree = 0;
        T[i].sibling = -1;
        T[i].parent = NIL;
    }
    for(int i=0; i<n; i++) {
        int t;
        cin >> t;
        cin >> T[t].left >> T[t].right;
        if(T[t].left != NIL) {
            T[T[t].left].parent = t;
            T[t].degree++;
        }
        if (T[t].right != NIL) {
            T[T[t].right].parent = t;
            T[t].degree++;
        }
        if(T[t].degree == 2) {
            T[T[t].left].sibling = T[t].right;
            T[T[t].right].sibling = T[t].left;
        } else {
            if(T[t].left != NIL)
                T[T[t].left].sibling = -1;
            if (T[t].right != NIL)
                T[T[t].right].sibling = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(T[i].parent == NIL) root = i;
    }

    calcDepth(&T[root]);
    calcHeight(&T[root]);
    for (int i = 0; i < n; i++) {
        print(i);
    }
}
