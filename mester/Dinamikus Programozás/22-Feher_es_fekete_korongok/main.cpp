#include <iostream>

using namespace std;

int* korongok;
int elso, utolso, N;

int** DP;

int lepFeher(int,int);
int lepFekete(int,int);

int lepFeher(int elso, int utolso){
    if(DP[elso][utolso]>=0)
        return DP[elso][utolso];

    int val = 0;
    if(elso == utolso)
        val = korongok[elso] == 1 ? 1 : 0;  /// 1 -> feher, 0 -> fekete
    else{
        val = max(lepFekete(elso+1,utolso)+korongok[elso], lepFekete(elso,utolso-1)+korongok[utolso]);
    }

    DP[elso][utolso] = val;
    //cout<<elso<<" - "<<utolso<<":   "<<val<<"\n";
    return val;
}

int lepFekete(int elso, int utolso){
    if(DP[elso][utolso] >= 0)
        return DP[elso][utolso];

    int val = 0;
    if(elso==utolso)
        val = 0;
    else{
        val = min(lepFeher(elso+1,utolso), lepFeher(elso,utolso-1));
    }

    DP[elso][utolso] = val;
    //cout<<elso<<" - "<<utolso<<":   "<<val<<"\n";
    return val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>N;
    korongok = new int[N];
    elso = 0; utolso = N-1;

    DP = new int*[N];
    for(int i = 0; i < N; ++i){
        cin>>korongok[i];
        DP[i] = new int[N];
        for(int j = 0; j < N; ++j)
            DP[i][j] = -1;
    }

    cout<<lepFeher(elso,utolso)<<"\n";

    delete[] korongok;
    return 0;
}
