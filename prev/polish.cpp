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
    stack<int> s;
    int n;
    scanf("%d", &n);
    s.push(n);
    char t[10];
    while(scanf("%s", t) != EOF){       
        if(t[0] == '+'){
            int f = s.top();
            s.pop();
            int p = s.top();
            s.pop();
            s.push(p+f);
        }else if(t[0] == '-'){
            int f = s.top();
            s.pop();
            int p = s.top();
            s.pop();
            s.push(p-f);
        }else if(t[0] == '*'){
            int f = s.top();
            s.pop();
            int p = s.top();
            s.pop();
            s.push(p*f);
        }else{
            s.push(atoi(t));
        }
    }
    cout << s.top() << '\n';
}