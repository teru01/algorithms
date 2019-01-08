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

int main() {
    int n, m, x, y;
    int *A, *B;
    cin >> n;
    cin >> m;
    cin >> x;
    cin >> y;
    A = new int[n];
    B = new int[m];
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >>B[i];
    }
    int xmax = -1000, ymin = 1000;
    for (int i = 0; i < n; i++)
    {
        xmax = max(xmax, A[i]);
    }
    for (int i = 0; i < m; i++)
    {
        ymin = min(ymin, B[i]);
    }
    if(xmax < ymin && x < ymin && xmax < y) cout << "No War" << endl;
    else cout << "War" << endl;
    delete[] A;
    delete[] B;
 }