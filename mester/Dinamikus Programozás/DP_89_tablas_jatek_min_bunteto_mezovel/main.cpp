/**
ELTE-MESTER / Haladó / Dinamikus Programozás / 89. Táblás játék legkevesebb büntető mezővel
2017.09.12
**/

#include <iostream>
#include <stack>

using namespace std;
int N, M;

enum class TIPUS{
    URES, BUNTETO, CSAPDA
};

struct mezo{
public:
    TIPUS tipus;
    int optErtek;
    char irany;

    mezo(){
        //cout<<"allocated mezo\n";
        tipus = TIPUS::URES;
        optErtek = 0;
        irany = 'N';
    }
};

mezo** tabla;

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    int temp;
    tabla = new mezo*[N];
    for(int i = 0; i < N; ++i){
        tabla[i] = new mezo[M];
        for(int j = 0; j < M; ++j){
            cin>>temp;
            switch(temp){
            case 0:
                tabla[i][j].tipus = TIPUS::URES;
                break;
            case 1:
                tabla[i][j].tipus = TIPUS::BUNTETO;
                break;
            case 2:
                tabla[i][j].tipus = TIPUS::CSAPDA;
                break;
            }
            tabla[i][j].optErtek = -1;
        }
    }

    if(tabla[0][0].tipus == TIPUS::CSAPDA){
        cout<<"-1\n";
        return 0;
    }

    tabla[0][0].optErtek = 0; /// kezdo buntatomezot nem vesszuk figyelembe, ez a mezo mar biztosan nem csapda
    for(int j = 1; j < M; ++j){
        if(tabla[0][j].tipus != TIPUS::CSAPDA && tabla[0][j-1].optErtek > -1){
            tabla[0][j].optErtek = tabla[0][j-1].optErtek + (tabla[0][j].tipus == TIPUS::BUNTETO ? 1 : 0);
            tabla[0][j].irany = tabla[0][j].optErtek > -1 ? 'J' : 'N';
        } else
            tabla[0][j].optErtek = -1;
    }


    for(int n = 1; n < N; ++n){
        if(tabla[n][0].tipus != TIPUS::CSAPDA && tabla[n-1][0].optErtek > -1){
            tabla[n][0].optErtek = tabla[n-1][0].optErtek + (tabla[n][0].tipus == TIPUS::BUNTETO ? 1 : 0);
            tabla[n][0].irany = tabla[n][0].optErtek > -1 ? 'L' : 'N';
        } else
            tabla[n][0].optErtek = -1;


        for(int m = 1; m < M; ++m){
            if(tabla[n][m].tipus == TIPUS::CSAPDA){
                tabla[n][m].optErtek = -1;
                continue;
            }

            int minOpt;
            char irany;
            if(tabla[n][m-1].optErtek > -1){
                if(tabla[n-1][m].optErtek > -1){
                    if(tabla[n][m-1].optErtek < tabla[n-1][m].optErtek){
                        minOpt = tabla[n][m-1].optErtek;
                        irany = 'J';
                    } else {
                        minOpt = tabla[n-1][m].optErtek;
                        irany = 'L';
                    }
                } else {
                    minOpt = tabla[n][m-1].optErtek;
                    irany = 'J';
                }
            } else {
                if(tabla[n-1][m].optErtek > -1){
                    minOpt = tabla[n-1][m].optErtek;
                    irany = 'L';
                } else {
                    minOpt = -1;
                    irany = 'N';
                }
            }



            if(minOpt == -1){
                tabla[n][m].optErtek = -1;
                tabla[n][m].irany = 'N';
                continue;
            } else {
                tabla[n][m].optErtek = minOpt + (tabla[n][m].tipus == TIPUS::BUNTETO ? 1 : 0);
                tabla[n][m].irany = irany;
            }

        }
    }

    cout<<tabla[N-1][M-1].optErtek<<"\n";
    if(tabla[N-1][M-1].optErtek == -1)
        return 0;
    int n = N-1;
    int m = M-1;
    stack<char> ut;
    while(!(n == 0 && m == 0)){
        ut.push(tabla[n][m].irany);
        if(tabla[n][m].irany == 'J')
            --m;
        else if(tabla[n][m].irany == 'L')
            --n;
        else
            cout<<"shit ";
    }
    while(ut.size()>0){
        cout<<ut.top();
        ut.pop();
    }
    cout<<"\n";
    return 0;
}
