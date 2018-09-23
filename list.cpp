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

using namespace std;
struct Node {
    Node *prev;
    Node *next;
    int key;
};

Node *makeNode(int key, Node *prev, Node *next)
{
    Node *node = new Node();
    node->key = key;
    node->next = next;
    node->prev = prev;
    return node;
}

void insertFirst(Node** firstNode, Node** lastNode) {
    int x;
    scanf("%d", &x);
    Node *newFirstNode = makeNode(x, nullptr, *firstNode);
    if (*firstNode)
    {
        newFirstNode->next->prev = newFirstNode;
    }
    else
    {
        *lastNode = newFirstNode;
    }
    *firstNode = newFirstNode;
}

void deleteNode(Node** firstNode, Node** lastNode) {
    int x;
    scanf("%d", &x);
    for (Node *node = *firstNode; node != nullptr; node = node->next)
    {
        if (node->key != x)
            continue;

        if (node->prev && node->next)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            break;
        }
        else if (node->prev == nullptr && node->next)
        {
            *firstNode = node->next;
            node->next->prev = nullptr;
            break;
        }
        else if (node->prev && node->next == nullptr)
        {
            *lastNode = node->prev;
            node->prev->next = nullptr;
            break;
        }
        else
        {
            *firstNode = nullptr;
            *lastNode = nullptr;
            break;
        }
    }
}

void deleteFirst(Node** firstNode, Node** lastNode) {
    if ((*firstNode)->next)
    {
        (*firstNode)->next->prev = nullptr;
    }
    else
    {
        *lastNode = nullptr;
    }
    *firstNode = (*firstNode)->next;
}

void deleteLast(Node** firstNode, Node** lastNode) {
    if ((*lastNode)->prev)
    {
        (*lastNode)->prev->next = nullptr;
    }
    else
    {
        *firstNode = nullptr;
    }
    *lastNode = (*lastNode)->prev;
}



void printNode(Node* firstNode, Node* lastNode) {
    for (Node *node = firstNode; node != nullptr; node = node->next)
    {
        if (node != firstNode)
        {
            cout << " ";
        }
        cout << node->key;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    Node nil;
    nil.key = -1;
    nil.next = &nil;
    nil.prev = &nil;
    for(int i=0; i<n; i++) {
        char command[20];
        
        scanf("%s", &command);
        if(!strcmp(command, "insert")) {
            insertFirst(&(nil.next), &(nil.prev));
        } else if(!strcmp(command, "delete")) {
            deleteNode(&(nil.next), &(nil.prev));
        } else if(!strcmp(command, "deleteFirst")) {
            deleteFirst(&(nil.next), &(nil.prev));
        } else if(!strcmp(command, "deleteLast")) {
            deleteLast(&(nil.next), &(nil.prev));
        }
    }
    printNode(nil.next, nil.prev);
}