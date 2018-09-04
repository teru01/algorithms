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

void printAry(int a[], int n){
    for(int k=0; k<n; k++){
            if(k == n-1){
                printf("%d\n", a[k]);
                continue;
            }
            printf("%d ", a[k]);
    }
}

int main(){
    int n, a[100];
    scanf("%d", &n);
    for(int m=0; m<n; m++){
        scanf("%d", &a[m]);
    }
    printAry(a, n);
    for(int i=1; i<n; i++){
        int j = i-1;
        int p = a[i];
        while(p < a[j] && j >= 0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = p;
        printAry(a, n);
    }
}