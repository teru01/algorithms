#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
void alt_int(int *n){
    
}

int main(){
    vector<int> vc;
    int n = 3;
    map<int, char> mp;
    while(n--){
        int x;
        cin >> x;
        vc.push_back(x);
        mp[n] = (char)x;
    }
    for(int i=0; i<vc.size(); i++){
        cout << vc[i]/2 << ' ' << mp[i] << '\n';
    }
}