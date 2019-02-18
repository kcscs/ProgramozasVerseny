#include <iostream>
#define MAX_N 20010
#define MAX_P 200
using namespace std;

typedef short int si;

int N, a, sum;
int db[MAX_P];

struct segTree{
    int arr[MAX_P*2];
    int ind[MAX_P*2];

    inline int bal(int i){
        return i*2+1;
    }

    inline int jobb(int i){
        return i*2+2;
    }

    inline int szulo(int i){
        return (i-1)/2;
    }

    void init(int i, int fb, int fj){
        if(fb == fj){
            ind[fb] = i;
            return;
        }
        int mid = (fb+fj)/2;
        init(bal(i), fb, mid);
        init(jobb(i), mid+1, fj);
    }

    void novel(int index){    /// 0 alapu index db-ben
        index = ind[index];
        //cout<<"nov: "<<ind<<endl;
        ++arr[index];
        while(index != 0){
            index = szulo(index);
            //cout<<"nov: "<<index<<endl;
            ++arr[index];
        }
    }

    int osszeg(int i, int fb, int fj, int& b, int& j){
        //cout<<"keres: "<<fb<<' '<<fj<<" cs: "<<i<<" val: "<<arr[i]<<endl;
        if(fj < b || fb > j)
            return 0;
        if(fb >= b && fj <= j)
            return arr[i];

        int mid = (fb+fj)/2;
        return osszeg(bal(i), fb, mid, b, j) + osszeg(jobb(i), mid+1, fj, b, j);
    }
};

segTree st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    st.init(0,0,MAX_P);
    //cout<<"init kesz"<<endl;
    for(int i = 0; i < N; ++i){
        cin>>a;
        //++db[a];
        //cout<<"a: "<<a<<endl;
        st.novel(a);
        sum = 0;

        int b = 0, j = a-1;

        cout<<st.osszeg(0,0,MAX_P,b,j)<<'\n';
    }
    return 0;
}
