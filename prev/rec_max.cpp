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

int recMax(int ary[], int f, int l){
    int m = (f+l)/2;
    if(l == f) return ary[l];
    int u = recMax(ary, f, m);
    int v = recMax(ary, m+1, l);
    return max(u, v);
}

int main(){
    int ary[] = {3,5,2,-1};
    cout << recMax(ary, 0, 3) << endl;
}