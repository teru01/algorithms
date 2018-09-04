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
void make_fractal(int n, double a, double b, double x, double y){
    double c = (2*a+x)/3;
    double d = (2*b+y)/3;
    double e = (a+2*x)/3;
    double f = (b+2*y)/3;
    //回転
    double th = M_PI * 60.0 / 180.0;
    double neox = cos(th)*(e-c) - (f-d)*sin(th) + c;
    double neoy = (e-c)*sin(th) + (f-d)*cos(th) + d;
    //頂点の配列
    double newx[] = {a, c, neox, e, x};
    double newy[] = {b, d, neoy, f, y};
    
    if(n == 0){
        printf("%.8f %.8f\n", x, y);
        return;
    }
    if(n == 1){
        for(int i=1; i<5; i++){
            printf("%.8f %.8f\n", newx[i], newy[i]);
        }
        return;
    }
    for(int i=0; i<4; i++){
        make_fractal(n-1, newx[i], newy[i], newx[i+1], newy[i+1]);
    }
}

int main(){
    int n;
    cin >> n;
    printf("%.8f %.8f\n", 0.0, 0.0);
    make_fractal(n, 0.0, 0.0, 100.0, 0.0);
}
//ACできない。斜め直線に対する回転がうまくいかなかった。