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

int partition(int* A, int p, int r) {
    int x = A[r];
    int i = p-1;
    for(int j=p; j<r; j++) {
        if(A[j] <= x) {
            i++;
            int t = A[j];
            A[j] = A[i];
            A[i] = t;
        }
    }
    int t = A[i+1];
    A[i+1] = x;
    A[r] = t;
    return i+1;
}

int main() {
    int n;
    cin >> n;
    int *A = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int q = partition(A, 0, n-1);
    for(int i=0; i<n; i++) {
        if(i != 0) cout << " ";
        if(i == q) cout << "[";
        cout << A[i];
        if (i == q) cout << "]";
    }
    cout << endl;
}