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
    int *p = new int[n+1];
    for(int i=0; i<n; i++) {
        cin >> p[i];
    }
    p[n] = -1;
    cin >> m;
    //int *q = new int[m];
    int q, c=0;
    for(int i=0; i<m; i++) {
        cin >> q;
        int k = 0;
        while(p[k] != -1) {
            if(q == p[k]) {
                c++;
                break;
            }
            k++;
        }
    }
    cout << c << endl;
}