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
int T[251];
void compbintree() {

}
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> T[i];
    }
    for(int i=1; i<=n; i++) {
        cout << T[i-1] << ", ";
        if(i/2-1 >= 0) {
            cout << T[i/2-1] << ", ";
        }
        if(2*i-1 <= n-1) {
            cout << T[2*i-1] << ", ";
        }
        if(2*i <= n-1) {
            cout << T[2*i] << ", ";
        }
        cout << "\n";
    }
}
