#include <iostream>
#include <limits.h>
#define MAX_N 100010
using namespace std;

int N, K, dj, db;
int tav[MAX_N];
int bal, jobb;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>K;
    for(int i = 0; i < N; ++i){
        cin>>tav[i];
    }
    tav[N] = INT_MAX;

    bal = 1;
    jobb = K;

    cout<<bal+1<<' '<<jobb+1<<'\n';
    for(int i = 1; i < N-1; ++i){
        if(bal == i)
            --bal;
        if(jobb < i){
            ++jobb;
            ++bal;
        }

        db = tav[i]-tav[bal];
        dj = tav[jobb+1]-tav[i];
        while(dj < db){
            ++bal; ++jobb;
            db = tav[i]-tav[bal];
            dj = tav[jobb+1]-tav[i];
        }

        cout<<bal+1<<' '<<(jobb == i ? i : (jobb+1))<<'\n';
    }
    cout<<N-K<<' '<<N-1<<'\n';
    return 0;
}
