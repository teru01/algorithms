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
void trace(string *a, int n)
{
    for (int k = 0; k < n; k++)
    {
        if (k != 0)
            cout << ' ';
        cout << a[k];
    }
    cout << '\n';
}

void selection_sort(string *a, int n) {
    for (int i = 0; i < n; i++)
    {
        int minj = i;
        for (int j = i; j < n; j++)
        {
            if (a[j][1] < a[minj][1])
            {
                minj = j;
            }
        }
        if (i != minj)
        {
            string t = a[i];
            a[i] = a[minj];
            a[minj] = t;
        }
    }
}

void bubble_sort(string *a, int n)
{
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int j = n - 1; j >= 1; j--)
        {
            if (a[j][1] < a[j - 1][1])
            {
                string t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
                flag = true;
            }
        }
    }
}
bool is_stable(string *a, string *b, int n) {
    //i < j
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for (int k = 0; k < n; k++){
                for (int l = k+1; l < n; l++){
                    if (b[i][1] == b[j][1])
                    {
                        if(b[i] == a[l] && b[j] == a[k]) return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    string *a = new string[n];
    string *b = new string[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
        cin >> b[i];
    }

    bubble_sort(a, n);
    trace(a, n);
    if(is_stable(a, b, n)) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << '\n';
    }
    
    selection_sort(a, n);
    trace(a, n);
    cout << is_stable(a, b, n) ? "Stable" : "Not stable" << '\n';
}