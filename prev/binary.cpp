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
 
/*昇順でn桁の2進数を全て表示せよ*/ 
using namespace std;
int msize, *S;
void bit(int n,int *S){
    if(n == msize){
        for(int i=0; i<msize; i++){
            cout << S[i];
        }
        cout << endl;
        return;
    }
    S[n] = 0;
    bit(n+1, S);
    S[n] = 1;
    bit(n+1, S);
}

int main(){
    cin >> msize;
    int *S;
    S = (int *)calloc(msize, sizeof(int));
    bit(0, S);
}