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
#include<limits.h>
using namespace std;
void swap(int A[], int i, int j){
    int q = A[i];
    A[i] = A[j];
    A[j] = q;
}

int partition(int A[], int p, int q){
    int t = p;
    while(p < q){
        if(A[p] < A[q]){
            swap(A, p, t);
            t++;
        }
        p++;
    }
    swap(A, t, q);
    cout << t << endl;
    return t;
}

void quicksort(int A[], int p, int q){
    if(p >= q) return;
    int r = partition(A, p, q);
    quicksort(A, p, r-1);
    quicksort(A, r+1, q);
}

int main(){
    int n;
    cin >> n;
    int *A = new int[n];
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    quicksort(A, 0, n-1);
    // partition(A, 0, n-1);
    for(int i=0; i<n; i++){
        if(i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}