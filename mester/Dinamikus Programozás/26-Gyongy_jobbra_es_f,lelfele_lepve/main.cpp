#include <iostream>
#include <stack>
using namespace std;
struct cella;
int M, N;
cella** tabla;
struct cella{
public:
    int gyongyok;
    //bool kiszamitva = false;
    char irany;
    int nagyobb = -1; int kisebb = -1;    /// kivalasztott cellak az uton
    /*int nagyobb_m, nagyobb_n;
    int kisebb_m, kisebb_n;*/

    void evaluate(int val, char dir){
        if(nagyobb == -1){
            nagyobb = val;
            irany = dir;
        } else {
            if(val > nagyobb){
                kisebb = nagyobb;
                nagyobb = val;
                irany = dir;
            } else {
                if(kisebb == -1 || val > kisebb){
                    kisebb = val;
                    irany = dir;
                }
            }
        }
    }

    inline int pontszam(){
        return kisebb+nagyobb;
    }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin>>M>>N;
    tabla = new cella*[M];
    for(int m = 0; m < M; ++m){
        tabla[m] = new cella[N];
        for(int n = 0; n < N; ++n){
            cin>>tabla[m][n].gyongyok;
        }
    }

    tabla[0][0].irany = 'S';
    tabla[0][0].nagyobb = tabla[0][0].gyongyok;
    for(int n = 1; n < N; ++n){
        cella balrol = tabla[0][n-1];
        balrol.evaluate(tabla[0][n].gyongyok, 'J');
        balrol.gyongyok = tabla[0][n].gyongyok;
        //if(balrol.pontszam()>tabla[0][n].pontszam())
            tabla[0][n] = balrol;
    }

    for(int m = 1; m < M; ++m){
        cella fentrol0 = tabla[m-1][0];
        fentrol0.evaluate(tabla[m][0].gyongyok,'L');
        fentrol0.gyongyok = tabla[m][0].gyongyok;
        //if(fentrol0.pontszam()>tabla[m][0].pontszam())
            tabla[m][0] = fentrol0;
        for(int n = 1; n < N; ++n){
            cella fentrol = tabla[m-1][n];
            cella balrol = tabla[m][n-1];

            fentrol.evaluate(tabla[m][n].gyongyok,'L');
            fentrol.gyongyok = tabla[m][n].gyongyok;

            balrol.evaluate(tabla[m][n].gyongyok,'J');
            balrol.gyongyok = tabla[m][n].gyongyok;

            if(fentrol.pontszam()>balrol.pontszam()){
                tabla[m][n] = fentrol;
                tabla[m][n].irany = 'L';
            }
            else{
                tabla[m][n] = balrol;
                tabla[m][n].irany = 'J';
            }
        }
    }

    cout<<tabla[M-1][N-1].pontszam()<<"\n";

    int nagyobb, kisebb;
    int n_m = -1; int n_n = -1; int k_m = -1; int k_n = -1;
    cella megoldas = tabla[M-1][N-1];
    nagyobb = megoldas.nagyobb;
    kisebb = megoldas.kisebb;

    char curDir = megoldas.irany;
    int m = M-1;
    int n = N-1;
    stack<char> ut;
    while(!(m == 0 && n == 0)){
        ut.push(tabla[m][n].irany);
        //cout<<" m: "<<m<<"  n: "<<n<<"    gy: "<<tabla[m][n].gyongyok<<"\n";
        if(tabla[m][n].irany=='J'){
            --n;
        } else if(tabla[m][n].irany=='L'){
            --m;
        }

        if(n_n == -1 && tabla[m][n].gyongyok == nagyobb){
            n_n = n;
            n_m = m;
        }
        if(k_n == -1 && tabla[m][n].gyongyok == kisebb){
            k_n = n;
            k_m = m;
        }
    }

    if(n_m < k_m || (n_m == k_m && n_n < k_n)){
        /// nagyobb elobb
        cout<<n_m+1<<" "<<n_n+1<<" "<<k_m+1<<" "<<k_n+1<<"\n";
    } else {
        cout<<k_m+1<<" "<<k_n+1<<" "<<n_m+1<<" "<<n_n+1<<"\n";
    }

    while(ut.size()>0){
        cout<<ut.top();
        ut.pop();
    }
    cout<<"\n";
}

