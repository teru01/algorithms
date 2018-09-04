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

int *poptwo(stack<string> s){
    int *a = new int[2];
    a[0] = stoi(s.top());
    s.pop();
    a[1]= stoi(s.top());
    s.pop();
    return a;
}

int main() {
    stack<string> s;
    string inp;
    while(cin >> inp) {
        int *a;
        string d;
        if(inp == "+") {
            a = poptwo(s);
            d = to_string(a[0] + a[1]);
        } else if(inp == "*") {
            a = poptwo(s);
            d = to_string(a[0] * a[1]);
        } else if(inp == "-") {
            a = poptwo(s);
            d = to_string(a[1] - a[0]);
        } else {
            d = inp;
        }
        s.push(d);
    }
    cout << stoi(s.top()) << endl;
    return 0;
}