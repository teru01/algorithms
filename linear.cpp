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

int main() {
    int n, m;
    cin >> n;
    int *p = new int[n];
    for(int i=0; i<n; i++) {
        cin >> p[i];
    }
    cin >> m;
    //int *q = new int[m];
    int q, c=0;
    for(int i=0; i<m; i++) {
        cin >> q;
        for(int j=0; j<n; j++) {
            if(q == p[j]) {
                c++;
                break;
            }
        }
    }
    cout << c << endl;
}