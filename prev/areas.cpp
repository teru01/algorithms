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
    char c;
    int cnt;
    int sum;
    stack<int> s1;
    stack<pair<int, int> > s2;
    for(int i=0; cin >> c; i++){
        if(c == '\\'){
            s1.push(i);
        }else if(c == '/' && s1.size() > 0){
            int bspos = s1.top();
            s1.pop();
            sum += i - bspos;
            int a = i - bspos;
            while(s2.size() > 0 && s2.top().first > bspos){
                a += s2.top().second;
                s2.pop();
            }
            s2.push(make_pair(bspos, a));
        }
    }
    vector<int> ans;
    while(s2.size() > 0){
        ans.push_back(s2.top().second);
        s2.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << sum << endl;
    cout << ans.size();
    for(int i=0; i<ans.size(); i++){
        cout << " ";
        cout << ans[i];
    }
    cout << endl;
}