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
int n;
int *S;
void rec(int i){
    if(i == n){
        for(int j=0; j<n; j++){
            cout << S[j];
        }
        cout << endl;
        return;
    }
    rec(i+1);
    S[i] = 1;
    rec(i+1);
    S[i] = 0;
}

int main(){
    cin >> n;
    S = (int *)calloc(n, sizeof(int));
    rec(0);
}
