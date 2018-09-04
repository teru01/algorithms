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

void printvect(vector<int> v){
    vector<int>::iterator it;
    for(it=v.begin(); it != v.end(); it++){
        cout << *it;
    }
    cout << endl;
}

int main(){
    int N = 4;
    vector<int> v;
    for(int i=0; i<N; i++){
        v.push_back(i);
    }
    printvect(v);
}