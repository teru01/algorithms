#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <complex>
#include <functional>

using namespace std;
struct m_proc {
    char name[11];
    int timeslice;
};

m_proc p[100000];
int head, tail;
void enqueue(m_proc lp) {
    p[tail] = lp;
    tail++;
    tail = tail % 100000;
}

m_proc dequeue() {
    m_proc lp = p[head];
    head++;
    head = head % 100000;
    return lp;
}

int main() {
    head = 0;
    int n, q;
    cin >> n;
    cin >> q;
    //m_proc *p = new m_proc[n];
    for(int i=0; i<n; i++) {
        scanf("%s", &(p[i].name));
        scanf("%d", &p[i].timeslice);
    }
    tail = n;
    int t = 0;
    int c = n;
    while(head != tail) {
        m_proc mp = dequeue();
        mp.timeslice -= q;
        t += q;
        if (mp.timeslice <= 0)
        {
            t += mp.timeslice;
            printf("%s %d\n", mp.name, t);
            continue;
        }
        enqueue(mp);
    }
}