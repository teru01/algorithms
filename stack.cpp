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

int main() {
    stack<int> s;
    string inp;
    while(cin >> inp) {
        int *a;
        string d;
        if(inp == "+") {
            int t = s.top();
            s.pop();
            int u = s.top();
            s.pop();
            s.push(t+u);
            continue;
        } else if(inp == "*") {
            int t = s.top();
            s.pop();
            int u = s.top();
            s.pop();
            s.push(t*u);
            continue;
        } else if(inp == "-") {
            int t = s.top();
            s.pop();
            int u = s.top();
            s.pop();
            s.push(u - t);
            continue;
        } else {
            s.push(stoi(inp));
        }
    }
    cout << s.top() << endl;
    return 0;
}