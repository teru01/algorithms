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

void bintree(int* A, int n) {
    for(int i=0; i<n; i++) {
        int key = i+1;
        printf("node %d: key = %d, ", key, A[i]);
        if(i != 0) {
            printf("parent key = %d, ", A[key/2 - 1]);
        }
        if(key * 2 <= n) {
            printf("left key = %d, ", A[key*2 - 1]);
        }
        if(key*2 + 1 <= n) {
            printf("right key = %d, ", A[key * 2]);
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cin >> n;
    int *A = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    bintree(A, n);
    delete[] A;
}