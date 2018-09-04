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
int *N;
int n;

bool can_make(int m, int i, int p){
    if(i == n){
       return (m == p) ? true:false;
    } 
    return can_make(m+N[i], i+1, p) || can_make(m, i+1, p);
}

int main(){
    int t;
    scanf("%d", &n);
    N = (int *)calloc(n, sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d", &N[i]);
    }
    scanf("%d", &t);
    int *dp = (int *)calloc(n, sizeof(int));
    for(int i=0; i<t; i++){
        int p;
        scanf("%d", &p);
        if(can_make(0, 0, p)){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}
