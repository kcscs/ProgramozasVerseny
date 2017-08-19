#include <iostream>
#include <limits.h>
#define ARR_SIZE 175

using namespace std;

int arr[ARR_SIZE][ARR_SIZE];
int N, TC;

inline int query(int x1, int y1, int x2, int y2){
    return arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1-1][y1-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>TC;
    for(int tc = 0; tc < TC; ++tc){
        cin>>N;
        for(int x = 1; x <= N; ++x) for(int y = 1; y <= N; ++y){        /// READ INPUT
            cin>>arr[x][y];
            arr[x+N][y] = arr[x][y];
            arr[x][y+N] = arr[x][y];
            arr[x+N][y+N] = arr[x][y];
        }

        /// Calculate Sum Matrix
        int N2 = N << 1;
        for(int x = 1; x <= N2; ++x) for(int y = 1; y <= N2; ++y){
            arr[x][y] += arr[x-1][y] + arr[x][y-1] - arr[x-1][y-1];
        }

        /*for(int x = 1; x <= N2; x++){
            for(int y = 1; y <= N2; y++)
                cout<<arr[x][y]<<"   ";
            cout<<"\n";
        }*/

        /// Kadane's algorithm extended to 2D and limited with N*N search space
        /// Not working becaouse of the wrapping of the array
        /*int maxSum = INT_MIN;
        int rsum = 0;
        int length = 1;
        int start = 0;
        for(int x1 = 1; x1 <= N; ++x1) for(int x2 = x1; x2 < x1+N; ++x2){
            rsum = 0;
            start = 1;
            for(int y = 1; y <= N2; ++y){
                if(rsum < 0){
                    rsum = 0;
                    start = y;
                    cout<<x1<<","<<x2<<"   resetting at: "<<y<<"\n";
                }

                rsum += query(x1,y,x2,y);
                if(y-start+1 > N){
                    rsum -= query(x1,start,x2,start);
                    ++start;
                }
                maxSum = max(maxSum,rsum);
            }

        }*/


        /// BRUTE-FORCE SOLUTION
        int maxSum = INT_MIN;
        for(int x1 = 1; x1 <= N; ++x1) for(int y1 = 1; y1 <= N; ++y1)
        for(int x2 = x1; x2 < x1+N && x2 <= N2; ++x2) for(int y2 = y1; y2 < y1+N && y2 <= N2; ++y2){
            maxSum = max(maxSum, query(x1,y1,x2,y2));
        }
        cout<<maxSum<<"\n";
    }
    return 0;
}
