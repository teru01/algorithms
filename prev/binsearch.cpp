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
    int middle = (last+first)/2;
    if(first >= last){
        return (p == ary[last]) ? true:false;
    }
    if(p < ary[middle]){
        return binsearch(p, ary, first, middle-1);
    }else if(p > ary[middle]){
        return binsearch(p, ary, middle+1, last);
    }else{
        return true;
    }
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
        int left = 0, right = n-1;
        int p = T[i];
        while(left <= right){
            int middle = (right + left)/2;
            if(p == N[middle]){
                cnt++;
                break;
            }else if(p < N[middle]){
                right = middle - 1;
            }else{
                left = middle + 1;
            }
        }
        //if(binsearch(T[i], N, 0, n-1)) cnt++;
    }
    cout << cnt;
    cout << endl;
}