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

bool binsearch(int f, int l, int s[], int key) {
    if(f > l) return false;
    int mid = (f+l)/2;
    if(key == s[mid]) return true;
    else if(key < s[mid]) return binsearch(f, mid-1, s, key);
    else if(key > s[mid]) return binsearch(mid+1, l, s, key);
}

int main() {
    int n, q;
    cin >> n;
    int *s = new int[n];
    for(int i=0; i<n; i++) {
        cin >> s[i];
    }
    cin >> q;
    int c = 0;
    for(int i=0; i<q; i++) {
        int r;
        cin >> r;
        int f = 0;
        int l = n-1; 
        if(binsearch(f, l, s, r)) {
            c++;
        }
        // for (int mid=(f + l) / 2; f <= l; mid = (f + l) / 2){
        //     if(s[mid] == r) {
        //         c++;
        //         break;
        //     }
        //     else if(s[mid] < r) {
        //         f = mid+1;
        //     }else if(s[mid] > r) {
        //         l = mid-1;
        //     }
        // }
    }
    cout << c << endl;
}