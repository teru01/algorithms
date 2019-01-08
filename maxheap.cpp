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
int left(int i) { return i*2; }
int right(int i){ return i*2+1;}
int parent(int i){return i/2;}
int H;
/**
 * O(logH)
 */
void maxHeapify(int* A, int i) {
    int l = left(i);
    int r = right(i);
    int maxind = i;
    if(l <= H && A[l] > A[maxind]) {
        maxind = l;
    }
    if(r <= H && A[r] > A[maxind]) {
        maxind = r;
    }

    if(maxind != i) {
        swap(A[i], A[maxind]);
        maxHeapify(A, maxind);
    }
}

void buildMaxHeap(int* A) {
    for(int i = H/2; i >= 1; i--) {
        maxHeapify(A, i);
    }
}

int main() {
    cin >> H;
    int *A = new int[H+1];
    for(int i=1; i<=H; i++) {
        cin >> A[i];
    }
    buildMaxHeap(A);
    for(int i=1; i<=H; i++) {
        cout << " " << A[i];
    }
    cout << "\n";
}
