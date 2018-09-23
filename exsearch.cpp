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
int *s;
int n;
bool exsrc(int value, int i) {
    if(i >= n) return false;
    if(value == 0) return true;
    return exsrc(value, i+1) || exsrc(value-s[i], i+1);
}
int main() {
    int q;
    cin >> n;
    s = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    cin >> q;
    for(int i=0; i<q; i++) {
        int r;
        cin >> r;
        bool result = exsrc(r, 0);
        if(result) {
            cout << "yes" << endl;
        }else {
            cout << "no" << endl;
        }
    }
}