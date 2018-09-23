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
long long cnt;
int A[1000000];
int n;
vector<int> G;
void insertion(int* a, int n, int g) {
    for (int i = g; i < n; i++)
    {
        int j = i - g;
        int c = a[i];
        while (j >= 0 && a[j] > c)
        {
            a[j + g] = a[j];
            j -= g;
            cnt++;
        }
        a[j + g] = c;
    }
}

void shellsort(int* A, int n) {
    cnt = 0;
    for(int k=1;;k = 3*k + 1) {
        if(k > n) break;
        G.push_back(k);
    }
    int m = G.size();
    for (int i = 0; i < n; i++)
    {
        insertion(A, n, G[m-1-i]);
    }
    cout << m << endl;
    for(int i=0; i<m; i++) {
        if(i != 0) cout << " ";
        cout << G[m-1-i];
    }
    cout << endl;
    cout << cnt << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int *A = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    shellsort(A, n);
}