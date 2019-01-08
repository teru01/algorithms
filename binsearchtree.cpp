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
#define MAX 500001
using namespace std;

struct Node
{
    int key;
    Node *parent, *left, *right;
    Node(int ikey) : key(ikey), parent(nullptr), left(nullptr), right(nullptr) {}
};

Node *root;

void insert(Node *parent, int key) {
    if(root == nullptr) {
        root = new Node(key);
        return;
    }
    if(key <= parent->key) {
        if(parent->left == nullptr) {
            parent->left = new Node(key);
            return;
        }
        insert(parent->left, key);
    } else {
        if (parent->right == nullptr)
        {
            parent->right = new Node(key);
            return;
        }
        insert(parent->right, key);
    }
}

void inorder(Node *node) {
    if(node == nullptr) return;
    inorder(node->left);
    printf(" %d", node->key);
    inorder(node->right);
}

void preorder(Node *node) {
    if(node == nullptr) return;
    printf(" %d", node->key);
    preorder(node->left);
    preorder(node->right);
}

bool find(Node *node, int key) {
    if(node == nullptr) return false;
    if(node->key == key) return true;
    return find(node->left, key) || find(node->right, key);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char s[20];
        scanf("%s", &s);
        if(strcmp(s, "insert") == 0) {
            int key;
            scanf("%d", &key);
            insert(root, key);
        }
        else if (strcmp(s, "find") == 0)
        {
            int key;
            scanf("%d", &key);
            if (find(root, key)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
        else if (strcmp(s, "print") == 0)
        {
            inorder(root);
            cout << "\n";
            preorder(root);
            cout << "\n";
        }
    }

}
