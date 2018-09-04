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

int main(){
    int a, b;
    cin >> a;
    cin >> b;
    for(int n=0; n<999; n++){
        for(int x=0; x<499500; x++){
            if(n*(n+1)/2 == a + x && (n+1)*(n+2)/2 == b + x){
                cout << x << endl;
                return 0;
            }
        }
    }
}