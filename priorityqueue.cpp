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

void maxHeapify(pair<char, int> *A, int i, int n)
{
    //cout << "start mH";
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l <= n && A[l].second >= A[i].second)
        largest = l;
    if (r <= n && A[r].second > A[largest].second)
        largest = r;
    if (largest != i)
    {
        swap(A[i], A[largest]);
        maxHeapify(A, largest, n);
    }
    //cout << "end mH";
}
int heapSize = 0;
pair<char, int> heap[2000001];

void extract() {
    //cout << "start ex";
    cout << heap[1].first << heap[1].second << endl;
    heap[1] = heap[heapSize];
    heapSize--;
    //cout << "before mH";
    maxHeapify(heap, 1, heapSize);
}
void insert(pair<char, int> key) {
    heapSize++;
    heap[heapSize] = key;
    int i = heapSize;
    //cout << heap[1].first << heap[1].second << endl;
    while(parent(i) >= 1 && heap[i].second > heap[parent(i)].second){
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

int main() {
    char command[20];
    while(true) {
        scanf("%s", &command);
        if (!strcmp(command, "insert"))
        {
            char c[3];
            scanf("%s", &c);
            char d = c[0];
            int n = c[1] - '0';
            auto p = make_pair(d, n);
            insert(p);
        }
        else if (!strcmp(command, "e"))
        {
            extract();
        }
        else if (!strcmp(command, "s"))
        {
            for(int i=1; i<=heapSize; i++) {
                cout << heap[i].first << heap[i].second << endl;
            }
        }
        else if (!strcmp(command, "fin"))
        {
            break;
        }
    }
}
