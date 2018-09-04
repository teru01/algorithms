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
#define N 10000
char **ht;

int myhash(char *s){
    int h = 0;
    for(int j=0; s[j] != '\0'; j++){
        h += trans(s[j]);
    }
    return h % N-1;
}
int trans(char c){
    switch(c){
        case 'A':
            return 0;
            break;
        case 'C':
            return 1;
            break;
        case 'G':
            return 2;
            break;
        case 'T':
            return 3;
            break;
    }
}
int main(){
    int n;
    *ht = (char *)calloc(N, sizeof(char *));
    char ope[7], val[13];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> ope;
        cin >> val;
        int code = myhash(val);
        if(strcmp(ope, "insert") == 0){
            if(ht[code] != 0){
                while(ht[myhash(++code)] == 0){
                    ;
                }
            ht[code] = val;
        }else if(strcmp(ope, "find") == 0){
            int origcode = code;
            while(ht[myhash(code++)] != val){
                if(ht[code] == 0 || code)
            }
        }
}