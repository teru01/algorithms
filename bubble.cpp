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

using namespace std;
void trace(int *a, int n)
{
    for (int k = 0; k < n; k++)
    {
        if (k != 0)
            cout << ' ';
        cout << a[k];
    }
    cout << '\n';
}
int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int c = 0;
    
    trace(a, n);
    cout << c << endl;
}