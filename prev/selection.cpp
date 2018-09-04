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

int selection_sort(int a[], int n){
    int cnt = 0;
    for(int i=0; i<n; i++){
        int minj = i;
        for(int j=i; j<n; j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        if(i != minj){
            swap(a[i], a[minj]);
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int n, a[100];
    cin >> n;
    for(int m=0; m<n; m++){
        cin >> a[m];
    }
    int cnt = selection_sort(a, n);
    for(int i=0; i<n; i++){
        if(i) cout << ' ';
        cout << a[i];
    } 
    cout << '\n';
    cout << cnt << endl;
}