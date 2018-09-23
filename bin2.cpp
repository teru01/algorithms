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

// void bin(int n, bool flag) {
//     if(n == 0) {
//         cout << endl;
//         return;
//     }
//     flag ? cout << "1" : cout << "0";
//     n--;
//     bin(n, false);
//     bin(n, true);
// }
int *S, msize;
void bin(int n, int* S) {
    if(n == msize) {
        for(int i=0; i<msize; i++) {
            cout << S[i];
        }
        cout << endl;
        return;
    }
    S[n] = 0;
    bin(n+1, S);
    S[n] = 1;
    bin(n+1, S);
}

int main() {
    cin >> msize;
    S = new int[msize];
    bin(0, S);
}