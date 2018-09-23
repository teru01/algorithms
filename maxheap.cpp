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

void maxHeapify(int* A, int i, int n) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l <= n && A[l] > A[i]) largest = l;
    if(r <= n && A[r] > A[largest]) largest = r;
    if(largest != i) {
        int t = A[i];
        A[i] = A[largest];
        A[largest] = t;
        maxHeapify(A, largest, n);
    }
}

int main() {
    int n;
    cin >> n;
    int *A = new int[n+1];
    //1オリジン
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    for(int i=n/2; i>=1; i--) {
        maxHeapify(A, i, n);
    }
    for(int i=1; i<=n; i++) {
        cout << " " << A[i];
    }
    cout << endl;
    delete[] A; 
}