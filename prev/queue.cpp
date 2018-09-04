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
struct Process {
    char name[11];
    int t;
};
int first = 0;
int last = 0;
#define SIZE 100000
Process a[SIZE];

void enqueue(Process p, int np){
    a[last] = p;
    last++;
    last = last % SIZE;
}

Process dequeue(int np){
    Process q = a[first];
    first++;
    first = first % SIZE;
    return q;
}

int main(){
    int np, q, cur = 0;
    scanf("%d %d", &np, &q);
    for(int i=0; i<np; i++){
        scanf("%s %d", a[i].name, &(a[i].t));
        enqueue(a[i], np);
    }
    while(first != last){
        Process p = dequeue(np);
        p.t -= q;
        cur += q;
        if(p.t <= 0){
            cur += p.t;
            cout << p.name << ' ' << cur << endl;
            continue;
        }
        enqueue(p, np);
    }
}

/**
 * 
5 100
p1 150
p2 80
p3 200
p4 350
p5 20
**/