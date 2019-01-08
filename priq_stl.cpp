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
#include <climits>
using namespace std;
int main() {
    priority_queue<pair<in>> PQ;
    PQ.push(1);
    PQ.push(6);
    PQ.push(4);
    PQ.push(10);
    for(int i=0; i<4; i++) {
        cout << PQ.top() << endl;
        PQ.pop();
    }
}
