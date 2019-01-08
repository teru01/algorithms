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
int T[100] = {0};
int fibo(int n) {
    if(T[n] != 0) return T[n];
    T[n] = fibo(n-1) + fibo(n-2);
    return T[n];
}
int main() {
    T[0] = T[1] = 1;
    int n;
    cin >> n;
    cout << fibo(n) << endl;
}
