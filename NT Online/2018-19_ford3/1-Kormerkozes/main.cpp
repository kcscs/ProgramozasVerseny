#include <iostream>
#include <algorithm>
#define MAX_N 16
#define NINCS -1
using namespace std;

int N, M, a;
bool foglalt[MAX_N][MAX_N];

int par[MAX_N];

bool keres(int i){
    //cout<<"ker: "<<i<<endl;
    if(i == N){
        for(int i = 0; i < N; ++i){
            if(par[i] != NINCS){
                cout<<i+1<<' '<<par[i]+1<<'\n';
                par[par[i]] = NINCS;
                par[i] = NINCS;
            }
        }
        return true;
    }
    if(par[i] != NINCS)
        return keres(i+1);

    for(int j = 0; j < N; ++j){
        if(i != j && par[j] == NINCS && !foglalt[i][j]){
            foglalt[i][j] = foglalt[j][i] = true;
            par[i] = j;
            par[j] = i;
            if(keres(i+1))
                return true;
            par[i] = par[j] = NINCS;
            foglalt[i][j] = foglalt[j][i] = false;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    cin>>N>>M;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin>>a;
            --a;
            foglalt[i][a] = true;
            //foglalt[a][i] = true;
        }
    }

    fill(par,par+N,NINCS);

    keres(0);
    return 0;
}
