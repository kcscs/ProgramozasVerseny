#include <iostream>
#include <stack>
using namespace std;

int M, N;
int** tabla;
int** DP;
char** dir;
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>M>>N;
    tabla = new int*[M];
    DP = new int*[M];
    dir = new char*[M];
    for(int i = 0; i < M; ++i){
        tabla[i] = new int[N];
        DP[i] = new int[N];
        dir[i] = new char[N];
        for(int j = 0; j < N; ++j){
            cin>>tabla[i][j];
            DP[i][j] = -1;
        }
    }

    DP[0][0] = tabla[0][0];
    dir[0][0] = 'S';
    for(int n = 1; n < N; ++n){
        if(tabla[0][n] >= 0){
            if(DP[0][n-1] >= 0){
                DP[0][n] = DP[0][n-1]+tabla[0][n];
                dir[0][n] = 'J';
            }
            //DP[0][n] = DP[0][n-1] >= 0 ? DP[0][n-1]+tabla[0][n] : -1;
        }
    }

    for(int m = 1; m < M; ++m){
        if(tabla[m][0] >= 0 && DP[m-1][0] >= 0){
            DP[m][0] = DP[m-1][0]+tabla[m][0];
            dir[m][0] = 'L';
            //DP[m][0] = DP[m-1][0] >= 0 ? DP[m-1][0]+tabla[m][0] : -1;
        }
        for(int n = 1; n <= N; ++n){
            if(tabla[m][n] >= 0){
                int f = DP[m-1][n];
                int b = DP[m][n-1];
                if(f == -1 && b == -1)
                    DP[m][n] = -1;
                else{
                    if(f > b){
                        DP[m][n] = f+tabla[m][n];
                        dir[m][n] = 'L';
                    } else {
                        DP[m][n] = b+tabla[m][n];
                        dir[m][n] = 'J';
                    }
                }
            }
        }
    }

    cout<<DP[M-1][N-1]<<"\n";
    int m = M-1;
    int n = N-1;
    stack<char> ut;
    while(!(m == 0 && n == 0)){
        if(dir[m][n] == 'J'){
            --n;
            ut.push('J');
        } else if(dir[m][n] == 'L'){
            --m;
            ut.push('L');
        }
    }

    while(ut.size()>0){
        cout<<ut.top();
        ut.pop();
    }
    cout<<"\n";
    return 0;
}
