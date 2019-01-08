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

int main() {
    vector<int> A(26, -1);
    vector<int> B(26, -1);
    string s,t;
    cin >> s >> t;
    for(int i=0; i<s.size(); i++) {
        int a = s[i] - 'a';
        int b = t[i] - 'a';
        if(A[a] != -1 || B[b] != -1) {
            if(A[a] != b || B[b] != a) {
                cout << "No" << endl;
                return 0;
            }
        }else {
            A[a] = b;
            B[b] = a;
        }
        
    }
    cout << "Yes" << endl;
}