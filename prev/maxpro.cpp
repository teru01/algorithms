#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, A[200000];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    int m = INT_MAX;
    int diff = INT_MIN;
    for(int i=0; i<n-1; i++){
        m = min(m, A[i]);
        diff = max(diff, A[i+1]-m);
    }
    cout << diff << endl;
}
