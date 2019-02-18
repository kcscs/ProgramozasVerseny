#include <iostream>
#define MAX_N 20010
#define MAX_P 200
using namespace std;

typedef short int si;

int N, a, sum;
int db[MAX_P];

struct fenwickTree{
    int ft[MAX_P+1];

    void inc(int ind){
        ++ind;  //ind = (ind & (-ind))
        for(; ind < MAX_P+1; ind += (ind & (-ind)))
            ++ft[ind];
    }

    int getSum(int ind){
        int sum = 0;
        ++ind;
        for(; ind; ind -= (ind & (-ind))){
            //cout<<"add: "<<ft[ind]<<" at: "<<ind<<'\n';
            sum += ft[ind];
        }
        return sum;
    }
};

fenwickTree fwt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    fill(fwt.ft,fwt.ft+MAX_P+1,0);
    for(int i = 0; i < N; ++i){
        cin>>a;
        //++db[a];
        //cout<<"a: "<<a<<endl;
        fwt.inc(a);
        /*for(int j = 0; j < 12; ++j)
            cout<<fwt.ft[j]<<' ';*/
        //cout<<'\n';

        cout<<fwt.getSum(a-1)<<'\n';
    }
    return 0;
}
