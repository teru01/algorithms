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

int main(){
    int N;
    cin >> N;
    int res = N;
    for(int i=0; i<=N; i++){
        int cc = 0;
        int t = i;
        while(t > 0){
            cc += t % 6;
            t /= 6;
        }
        t = N - i;
        
    }
}