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
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int diff = INT_MIN;
    int M, c;
    M = a[n-1];
    for(int i=n-2; i>=0; i--){
        if((c = M-a[i]) > diff) {
            diff = c;
        }
        if(a[i] > M) {
            M = a[i];
        }
    }
    cout << diff << endl;
}