#include <iostream>
#define MAX_N 20010
#define MAX_P 110
using namespace std;

typedef short int si;

int N, a, sum;
int db[MAX_P];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>a;
        ++db[a];
        sum = 0;
        for(int j = 1; j < a; ++j)
            sum += db[j];
        cout<<sum<<'\n';
    }
    return 0;
}
