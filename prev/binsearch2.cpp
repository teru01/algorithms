#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

bool binsearch(int p, int ary[], int first, int last){
    int mid = (first+last)/2;
    if(last < first) return false;
    if(p == ary[mid]) return true;
    else if(p > ary[mid]) return binsearch(p, ary, mid+1, last);
    else return binsearch(p, ary, first, mid-1);
}

int main(){
    int n, t;
    int N[100000], T[50000];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &N[i]);
    }
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> T[i];
    }

    int cnt = 0;
    for(int i=0; i<t; i++){
        int first = 0, last = n-1;
        int p = T[i];
        while(first <= last){
            int mid = (first+last)/2;
            if(p == N[mid]) {
                cnt++;
                break;
            }
            else if(p > N[mid]){
                first = mid + 1;
            }else{
                last = mid - 1;
            }
        }
    }
    cout << cnt;
    cout << endl;
}