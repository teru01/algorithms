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

using namespace std;
int left(int i) { return i * 2; }
int right(int i) { return i * 2 + 1; }
int parent(int i) { return i / 2; }

void maxHeapify(int *A, int i, int n)
{
    //cout << "start mH";
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l <= n && A[l] > A[i])
        largest = l;
    if (r <= n && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        int t = A[i];
        A[i] = A[largest];
        A[largest] = t;
        maxHeapify(A, largest, n);
    }
    //cout << "end mH";
}
int heapSize = 0;
int heap[2000001];

void extract() {
    //cout << "start ex";
    cout << heap[1] << endl;
    heap[1] = heap[heapSize];
    heapSize--;
    //cout << "before mH";
    maxHeapify(heap, 1, heapSize);
}
void insert(int key) {
    heapSize++;
    heap[heapSize] = key;
    int i = heapSize;
    while(parent(i) >= 1 && heap[i] > heap[parent(i)]){
        int t = heap[i];
        heap[i] = heap[parent(i)];
        heap[parent(i)] = t;
        i = parent(i);
    }
}

int main() {
    char command[20];
    while(true) {
        scanf("%s", &command);
        if (!strcmp(command, "insert"))
        {
            int n;
            scanf("%d", &n);
            insert(n);
        }
        else if (!strcmp(command, "extract"))
        {
            extract();
        }
        else if (!strcmp(command, "end"))
        {
            break;
        }
    }  
}