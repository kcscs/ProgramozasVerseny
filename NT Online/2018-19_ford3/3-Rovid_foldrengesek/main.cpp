#include <iostream>
#include <algorithm>
#define MAX_F 100010
using namespace std;

int K, M, f, hossz, maxhossz = 0;

int ido[MAX_F];
int idoDb = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>K>>M;
    for(int i = 0; i < K; ++i){
        cin>>f;
        for(int j = 0; j < f; ++j){
            //cin>>a;
            cin>>ido[idoDb];
            ++idoDb;
        }
    }

    ido[idoDb] = 0;
    ++idoDb;
    ido[idoDb] = M+1;
    ++idoDb;

    sort(ido, ido+idoDb);
    for(int i = 1; i < idoDb; ++i){
        hossz = ido[i]-ido[i-1]-1;
        if(hossz > maxhossz)
            maxhossz = hossz;
    }

    cout<<maxhossz<<'\n';
    return 0;
}
