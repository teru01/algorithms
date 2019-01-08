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
int H = 1;
using namespace std;
int left(int i) { return i*2; }
int right(int i){ return i*2+1;}
int parent(int i){return i/2;}

int heap[2000001];
/**
 * O(logH)
 */
void maxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int maxind = i;
    if(l <= H && heap[l] > heap[maxind]) {
        maxind = l;
    }
    if(r <= H && heap[r] > heap[maxind]) {
        maxind = r;
    }

    if(maxind != i) {
        swap(heap[i], heap[maxind]);
        maxHeapify(maxind);
    }
}

void insert(int v) {
    heap[H] = v;
    int i = H;
    while(parent(i) >= 1 && heap[i] > heap[parent(i)]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
    H++;
}

void extract() {
    cout << heap[1] << "\n";
    heap[1] = heap[--H];
    maxHeapify(1);
}

int main() {
    char command[20];
    while(true) {
        scanf("%s", &command);
        if (!strcmp(command, "insert"))
        {
            int val;
            scanf("%d", &val);
            insert(val);
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
