#include <iostream>
#include <limits.h>
#include <vector>
#define IMAX INT_MAX-100000
using namespace std;

int NtermA, NtermB, ossz;
struct aruhaz{
    int koltsA, koltsB;
    char raktar;
};

aruhaz* ahazak;

int** DP;
char** DPdir;

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>NtermA>>NtermB;
    ossz = NtermA+NtermB;
    ahazak = new aruhaz[ossz];
    DP = new int*[ossz];
    DPdir = new char*[ossz];
    for(int i = 0; i < ossz; ++i)
        cin>>ahazak[i].koltsA;

    for(int i = 0; i < ossz; ++i)
        cin>>ahazak[i].koltsB;

    DP[ossz-1] = new int[NtermA+1];
    DPdir[ossz-1] = new char[NtermA+1];
    DP[ossz-1][0] = ahazak[ossz-1].koltsB;
    DP[ossz-1][1] = ahazak[ossz-1].koltsA;
    DPdir[ossz-1][0] = 'B';
    DPdir[ossz-1][1] = 'A';
    for(int i = 2; i < NtermA+1; ++i)
        DP[ossz-1][i] = -1;

    for(int i = ossz-2; i >= 0; --i){
        DP[i] = new int[NtermA+1];
        DPdir[i] = new char[NtermA+1];
        if(i<ossz-NtermB){
            DP[i][0] = -1;
        } else {
            DP[i][0] = DP[i+1][0]+ahazak[i].koltsB;
            DPdir[i][0] = 'B';
        }

        for(int remA = 1; remA <= NtermA; ++remA){
            int remB = ossz-i-remA;
            if(remB > NtermB || NtermB < 0){
                DP[i][remA] = -1;
                continue;
            }

            if(DP[i+1][remA-1] == -1)
                DP[i][remA] = -1;
            else if(DP[i+1][remA] == -1){
                DP[i][remA] = DP[i+1][remA-1] + ahazak[i].koltsA;
                DPdir[i][remA] = 'A';
            }
            else{
                int a = DP[i+1][remA-1] + ahazak[i].koltsA;
                int b = DP[i+1][remA] + ahazak[i].koltsB;
                if(a <= b){
                    DP[i][remA] = a;
                    DPdir[i][remA] = 'A';
                }else{
                    DP[i][remA] = b;
                    DPdir[i][remA] = 'B';
                }
            }
        }
        delete[] DP[i+1];
    }
    cout<<DP[0][NtermA]<<"\n";
    int i = 0; int ra = NtermA;

    while(i<ossz){
        cout<<DPdir[i][ra];
        if(DPdir[i][ra] == 'A'){
            ++i; --ra;
        } else
            ++i;
    }
    cout<<"\n";
    return 0;
}
