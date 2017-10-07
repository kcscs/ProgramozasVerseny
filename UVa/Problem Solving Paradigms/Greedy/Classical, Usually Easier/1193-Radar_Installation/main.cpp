#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct Intervallum;

int pow(int alap, int kitevo){
    int val = 1;
    for(int i = 0; i < kitevo; ++i){
        val *= alap;
    }
    return val;
}

struct Intervallum{
public:
    int kezd, veg;

    Intervallum() {}
    Intervallum(int _kezd, int _veg){
        kezd = _kezd;
        veg = _veg;
    }
    Intervallum(int x, int y, int r){
        int sz = sqrt(pow(r,2)-pow(y, 2));
        kezd = x-sz;
        veg = x+sz;
    }

    ~Intervallum(){

    }

    bool atfed (const Intervallum& masik) const {
        if(masik.kezd < kezd)
            return masik.veg < kezd ? false : true;
        else
            return masik.kezd > veg ? false : true;
    }

    void operator&=(Intervallum& masik){
        kezd = masik.kezd;
        veg = min(veg, masik.veg);
    }

    void operator=(pair<int, int> jobb){
        kezd = jobb.first;
        veg = jobb.second;
    }

    bool operator<(Intervallum& masik){
        return kezd < masik.kezd;
    }

    void torol(){
        kezd = 0;
        veg = -1;
    }

    bool kivantorolve(){
        return (kezd == 0 && veg == -1);
    }
};


ostream& operator<<(ostream& bal, Intervallum& jobb){
    bal<<"["<<jobb.kezd<<"; "<<jobb.veg<<"]";
    return bal;
}

bool comp(Intervallum& bal, Intervallum& jobb){
    return bal.kezd < jobb.kezd;
}


int main()
{
    int n, d, tc;
    tc = 1;
    cin>>n>>d;
    while(n!=0){
        pair<int,int> szigetek[n];
        vector<Intervallum> ivk;
        bool nosol = false;
        for(int i = 0; i < n; ++i){
            cin>>szigetek[i].first>>szigetek[i].second;
            if(szigetek[i].second > d){
                nosol = true;

            }
            ivk.push_back(Intervallum(szigetek[i].first, szigetek[i].second, d));
            //cout<<ivk.back()<<"\n";
        }

        if(!nosol)
        sort(ivk.begin(), ivk.end(), comp);
        //sort(ivk.begin(), ivk.end());

        int db = n;

        if(!nosol)
        for(int i = 0; i < n-1; i++){
            if(ivk[i].atfed(ivk[i+1])){
                ivk[i] &= ivk[i+1];
                ivk[i+1].torol();
                swap(ivk[i], ivk[i+1]);
                db--;
            }
        }

        if(nosol)
            db = -1;

        cout<<"Case "<<tc<<": "<<db<<"\n";

        /*cout<<db<<" db:\n";
        for(int i = 0; i < n; ++i){
            if(!ivk[i].kivantorolve())
                cout<<ivk[i]<<"\n";
        }*/
        tc++;
        cin>>n>>d;
    }
    return 0;
}
