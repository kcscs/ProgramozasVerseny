#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#define LENGTH 20
#define MAX 100

int main()
{
    srand(time(NULL));
    int tomb[LENGTH];

    for(int i = 0; i < LENGTH; i++){
        tomb[i] = rand()%MAX;
    }

    std::sort(std::begin(tomb),std::end(tomb));
    int* kezd;
    int* veg;
    kezd = tomb; veg = kezd + LENGTH;
    //std::sort(kezd,veg);

    for(int i = 0; i < LENGTH; i++)
        std::cout<<tomb[i]<<" ";
    std::cout<<"\n";

    //int keres = tomb[rand()%LENGTH];
    int keres = rand()%MAX;
    std::cout<<"Keressuk: "<<keres<<"\n";
    int bal = 0, jobb = LENGTH-1;
    int kozep;
    while(bal != jobb){
        kozep = (bal+jobb)/2;
        if(tomb[kozep] == keres)
            bal = jobb;
        else if(tomb[kozep] < keres)
            bal = kozep+1;
        else
            jobb = kozep;
    }

    if(tomb[kozep] == keres)    ///Megtalaltuk
        std::cout<<" index: "<<kozep+1<<"\n";
    else
        std::cout<<"Nem talalt\n";
    return 0;
}
