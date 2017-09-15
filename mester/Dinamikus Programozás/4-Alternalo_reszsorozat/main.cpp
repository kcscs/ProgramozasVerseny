#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
int* sor;
vector<int> en, ecs, pn, pcs;

template <typename T>
ostream& operator<<(ostream& left, const vector<T>& right){
    int s = right.size()-1;
    for(int i = 0; i < s; ++i)
        left<<right[i]<<" ";
    left<<right[s]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>N;
    sor = new int[N];
    cin>>sor[0];
    en.push_back(sor[0]);
    pn.push_back(1);
    ecs.push_back(sor[0]);
    pcs.push_back(1);

    bool novn = true;
    bool novcs = false;
    for(int i = 1; i < N; ++i){
        cin>>sor[i];

        /// novekvovel kezd
        if(novn){
            if(sor[i] > en.back()){
                en.push_back(sor[i]);
                pn.push_back(i+1);
                novn = false;
            } else {
                en.back() = sor[i];
                pn.back() = i+1;
            }
        } else {
            if(sor[i] < en.back()){
                en.push_back(sor[i]);
                pn.push_back(i+1);
                novn = true;
            } else {
                en.back() = sor[i];
                pn.back() = i+1;
            }
        }

        /// csokkenovel kezd
        if(novcs){
            if(sor[i] > ecs.back()){
                ecs.push_back(sor[i]);
                pcs.push_back(i+1);
                novcs = false;
            } else {
                ecs.back() = sor[i];
                pcs.back() = i+1;
            }
        } else {
            if(sor[i] < ecs.back()){
                ecs.push_back(sor[i]);
                pcs.push_back(i+1);
                novcs = true;
            } else {
                ecs.back() = sor[i];
                pcs.back() = i+1;
            }
        }
    }

    if(en.size() > ecs.size()){
        cout<<en.size()<<"\n";
        cout<<pn;
    } else {
        cout<<ecs.size()<<"\n";
        cout<<pcs;
    }

    /*vector<char> a;   Test template operator
    for (int i = 32; i < 256; ++i)
        a.push_back((char)(i));
    cout<<a;*/
    return 0;
}
