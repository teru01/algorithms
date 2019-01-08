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


int lcs(string x, string y) {
    int c[1001][1001];
    int n = x.length();
    int m = y.length();
    for(int i = 0; i < n; i++) {
        c[i][0] = 0;
    }
    for(int j = 0; j < m; j++) {
        c[0][j] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(x[i-1] == y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
            } else {
                c[i][j] = max(c[i][j-1], c[i-1][j]);
            }
        }
    }
    return c[n][m];
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
    }
}
