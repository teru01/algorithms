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
#include<fstream>
 
using namespace std;

string isStable(int sb[], string src[], string dst[], int n){
    for(int s=0; s<n-1; s++){
        for(int t=s+1; t<n; t++){
            for(int i=0; i<n-1; i++){
                for(int j=i+1; j<n; j++){
                    if(sb[s] == sb[t] && src[s] == dst[j] && src[t] == dst[i]){
                        return "Not Stable";
                    }
                }
            }
        }
    }
    return "Stable";
}

string bubblesort(int b[], string a[], int n){
    string src[100];
    int sb[100];
    memcpy(src, a, n*sizeof(string));
    memcpy(sb, b, n*sizeof(int));
    for(int i=0; i<n; i++){
        for(int j=n-1; j>i; j--){
            if(b[j] < b[j-1]) {
                swap(b[j], b[j-1]);
                swap(a[j], a[j-1]);
            }
        }
    }
    return isStable(sb, src, a, n);
}

string selectsort(int b[], string a[], int n){
    string src[100];
    int sb[100];
    memcpy(src, a, n*sizeof(string));
    memcpy(sb, b, n*sizeof(int));
    for(int i=0; i<n; i++){
        int minj = i;
        for(int j=i+1; j<n; j++){
            if(b[j] < b[minj]) minj = j;
        }
        swap(a[i], a[minj]);
        swap(b[i], b[minj]);
    }
    return isStable(sb, src, a, n);
}
int main(){
    int n;
    char c[10];
    string a[100];
    string a2[100];
    int b[100];
    int b2[100];
    cin >> n;
    for(int m=0; m<n; m++){
        cin >> a[m];
    }
    for(int m=0; m<n; m++){
        b[m] = (int)(a[m][1] - 48);
    }
    memcpy(a2, a, n*sizeof(string));
    memcpy(b2, b, n*sizeof(int));
    string br = bubblesort(b, a, n);
    string sr = selectsort(b2, a2, n);

    for(int i=0; i<n; i++){
        if(i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    cout << br << endl;
    for(int i=0; i<n; i++){
        if(i) cout << ' ';
        cout << a2[i];
    }
    cout << '\n';
    cout << sr << endl;
    return 0;
}