/**
Longest Increasing Subsequence problem
2017.09.12
complexity: O(n log n)
**/
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
#define MIN_ERTEK -100
#define MAX_ERTEK 100
using namespace std;

int N;
int* sor;
int* rsor;

int csor[] = {62, 27, 59, 75, -53, 79, -4, 33, 62, -68, -53, 0, 40, 99, 18};

int main()
{
    srand((unsigned)time(NULL));
    rand();

    ios_base::sync_with_stdio(false);
    cin>>N;
    sor = new int[N];
    rsor = new int[N];
    for(int n = 0; n < N; ++n){
        sor[n] = rand()%(MAX_ERTEK-MIN_ERTEK+1)+MIN_ERTEK;
        rsor[n] = sor[n];
        cout<<sor[n]<<" ";
    }

    /*sor = csor;
    for(int i = 0; i < N; ++i)
        rsor[i] = csor[i];

    for(int n = 0; n < N; ++n)
        cout<<sor[n]<<" ";*/

    cout<<"\n\nSorted:\n";
    sort(rsor,rsor+N);
    for(int n = 0; n <N;++n)
        cout<<rsor[n]<<" ";
    cout<<"\n";

    /*int searchFor;
    cin>>searchFor;
    cout<<"lb: "<<*lower_bound(rsor,rsor+N,searchFor)<<"\n";
    cout<<"ub: "<<*upper_bound(rsor,rsor+N,searchFor)<<"\n";*/

    vector<int> v;
    v.push_back(sor[0]);
    int p[N];
    p[0] = 0;
    int h[N];
    h[0] = -1;

    int maxLen = 1;

    for(int i = 1; i < N; ++i){
        if(sor[i] > v.back()){
            v.push_back(sor[i]);
            p[maxLen] = i;
            h[i] = p[maxLen-1];
            maxLen++;
        } else if(sor[i] < v.front()){
            v[0] = sor[i];
            p[0] = i;
            h[i] = -1;
        } else {
            int ind = distance(v.begin(),lower_bound(v.begin(),v.end(),sor[i]));
            v[ind] = sor[i];
            p[ind] = i;
            h[i] = p[ind-1];
        }
    }

    cout<<"Longest: ("<<maxLen<<")\n";
    int ind = p[maxLen-1];
    stack<int> lis;
    while(ind != -1){
        lis.push(sor[ind]);
        ind = h[ind];
    }
    while(lis.size()>0){
        cout<<lis.top()<<" ";
        lis.pop();
    }
    return 0;
}
