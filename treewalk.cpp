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
#define MAX 26
using namespace std;

struct Node
{
    int parent, left, right;
};
Node T[MAX];

void travelPreorder(int root) {
    if(root == NIL) return;
    cout << " " << root;
    travelPreorder(T[root].left);
    travelPreorder(T[root].right);
}

void travelInorder(int root) {
    if (root == NIL)
        return;
    travelInorder(T[root].left);
    cout << " " << root;
    travelInorder(T[root].right);
}

void travelPostorder(int root)
{
    if (root == NIL)
        return;
    travelPostorder(T[root].left);
    travelPostorder(T[root].right);
    cout << " " << root;
}

int main()
{
    int n, root;
    cin >> n;
    for(int i=0; i<n; i++) {
        T[i].parent = T[i].left = T[i].right = NIL;
    }
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        cin >> T[t].left >> T[t].right;
        if (T[t].left != NIL)
        {
            T[T[t].left].parent = t;
        }
        if (T[t].right != NIL)
        {
            T[T[t].right].parent = t;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (T[i].parent == NIL)
            root = i;
    }
    cout << "Preorder" << endl;
    travelPreorder(root);
    cout << "\n";
    cout << "Inorder" << endl;
    travelInorder(root);
    cout << "\n";
    cout << "Postorder" << endl;
    travelPostorder(root);
    cout << "\n";
}
