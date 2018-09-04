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
int cnt9 = 0;
int cnt6 = 0;
int cnt1 = 0;
int cnt = 0;
int rec(int a){
    for(int i=1; i<6; i++){
        int val = (int)pow(9.0, (double)i);
        if(val > a) continue;
        cnt++;
        return rec(a - val);
    }
    for(int i=1; i<7; i++){
        int val = (int)pow(6.0, (double)i);
        if(val > a) break;
        cnt++;
        rec(a - val);
        return;
    }
    for(int i=0; i<100000; i++){
        int val = 1;
        if(val > a) break;
        cnt++;
        rec(a - val);
        return;
    }
}

int main(){
    int a;
    cin >> a;
    int res = a;
    for(int i=0; i<=a; i++){
        int cc = 0;
        int t = i;
        while(t > 0){
            cc += t % 6;
            t /= 6;
        }
        t = a - 1;
        
    }
    cout << cnt << endl;
}