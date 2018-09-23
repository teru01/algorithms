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

int c = 0;
void merge(int* A, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int* L = new int[n1+1];
    int* R = new int[n2+1];
    for(int i=0; i<n1; i++) {
        L[i] = A[l + i];
    }
    for(int i=0; i<n2; i++) {
        R[i] = A[mid+1 + i];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0;
    int j = 0;
    for(int k=l; k<=r; k++) {
        c++;
        if(L[i] < R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergesort(int* A, int l, int r) {
    int mid = (l + r) / 2;
    if(l == r) return;
    mergesort(A, l, mid);
    mergesort(A, mid+1, r);
    merge(A, l, mid, r);
}

int main() {
    int n;
    cin >> n;
    int* A = new int[n];
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
    mergesort(A, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        if(i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << c << endl;
}