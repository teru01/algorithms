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
#include <climits>

using namespace std;

int partition(pair<char, int> *pr, int p, int r)
{
    pair<char, int> x = pr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (pr[j].second <= x.second)
        {
            i++;
            pair<char, int> t = pr[j];
            pr[j] = pr[i];
            pr[i] = t;
        }
    }
    pair<char, int> t = pr[i + 1];
    pr[i + 1] = x;
    pr[r] = t;
    return i + 1;
}

void quicksort(pair<char, int> *pr, int p, int r)
{
    if(p < r) {
        int q = partition(pr, p, r);
        quicksort(pr, p, q-1);
        quicksort(pr, q+1, r);
    }
}

int main() {
    int n;
    cin >> n;
    pair<char, int> *pr = new pair<char, int>[n];
    pair<char, int> *prorig = new pair<char, int>[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pr[i].first;
        cin >> pr[i].second;
        prorig[i].first = pr[i].first;
        prorig[i].second = pr[i].second;
    }
    quicksort(pr, 0, n-1);
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=0; k<n-1; k++) {
                for(int l=k+1; l<n; l++) {
                    if(pr[i].second == pr[j].second && pr[i] == prorig[l] && pr[j] == prorig[k]) {
                        cout << "Not stable" << endl;
                        // cout << i << j << k << l << endl;
                        // cout << pr[i].first << pr[j].first << prorig[k].first << prorig[l].first << endl;
                        // cout << pr[i].second << pr[j].second << prorig[k].second << prorig[l].second << endl;
                        goto endloop;
                    } 
                }
            }
        }
    }
    cout << "Stable" << endl;
endloop:
    for(int i=0; i<n; i++) {
        cout << pr[i].first << " " << pr[i].second << endl;
    }
}