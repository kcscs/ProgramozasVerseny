///OWN IMPLEMENTATION
#include <iostream>
#include <cstdlib>  ///Needed for abs()
#include <vector>
using namespace std;

bool* occ_row;
bool* occ_col;
bool* occ_diag_NW_SE;
bool* occ_diag_SW_NE;

int N;
vector<pair<int,int>> solution;
int noSol = 0;

void backTrack(int n_placed){
    if(n_placed == N){  ///Solution found
        for(int i = 0; i < N; i++){
            cout<<solution[i].first<<","<<solution[i].second<<" ";
        }
        noSol++;
        cout<<"\n";
        return;
    }

    int r = n_placed;
        /*if(occ_row[r])
            continue;*/
        for(int c = 0; c < N; c++){
            if(occ_col[c])
                continue;
            if(occ_diag_NW_SE[r+c])
                continue;
            int swne = abs(N-1-r+c);
            if(occ_diag_SW_NE[swne])
                continue;

            ///Place queen
            //occ_row[r] = true;
            occ_col[c] = true;
            occ_diag_NW_SE[r+c] = true;
            occ_diag_SW_NE[swne] = true;
            solution.push_back(pair<int,int>(r,c));
            ///Explore
            backTrack(n_placed+1);
            ///Backtrack
            //occ_row[r] = false;
            occ_col[c] = false;
            occ_diag_NW_SE[r+c] = false;
            occ_diag_SW_NE[swne] = false;
            solution.pop_back();
        }

}


int main(){
    ios_base::sync_with_stdio(false);
    cout<<"Enter size of chess table: ";
    cin>>N;
    cout<<"Places where "<<N<<" queens should be placed so they don't attack each other:\n";

    occ_row = new bool[N];
    occ_col = new bool[N];
    occ_diag_NW_SE = new bool[N<<1];
    occ_diag_SW_NE = new bool[N<<1];
    //solution.resize(N);

    for(int i = 0; i < N; i++){
        occ_col[i] = false;
        occ_row[i] = false;
        occ_diag_NW_SE[i] = false;
        occ_diag_NW_SE[(N<<1)-i-1] = false;
        occ_diag_SW_NE[i] = false;
        occ_diag_SW_NE[(N<<1)-i-1] = false;
    }

    backTrack(0);

    cout<<"\nFound a total of "<<noSol<<" solutions.\n";

    delete[] occ_row;
    delete[] occ_col;
    delete[] occ_diag_NW_SE;
    delete[] occ_diag_SW_NE;

    cin.get();
    return 0;
}








///IMPLEMENTATION BASED ON "COMPETITIVE PROGRAMMING 3"

/*#include <iostream>
#include <cstdlib>
using namespace std;

int row[8]; ///The queen's position in the c-sth row (0<=c<=7)
int r_given, c_given; ///One queen's position is given (a,b)

bool isPositionSafe(int r, int c){
    for(int prev = 0; prev < c; prev++){
        if(row[prev] == r || (abs(row[prev]-r == abs(prev-c))))
            return false;
    }
    return true;
}

void backtrack(int c){
    if(c == 8 && row[c_given] == r_given){ ///Last queen is placed
            ///A solution is found
            for(int i = 0; i < 8; i++){
                cout<<row[i]+1<<","<<i+1<<" ";    //write solution
            }
            cout<<"\n";

    }
    {
        for(int r = 0; r < 8; r++){
            if(isPositionSafe(r,c)){
                row[c] = r;
                backtrack(c+1);
            }
        }
    }
}

int main()
{
    cin>>r_given>>c_given;
    c_given--; r_given--; //switch to zero based coordinates

    backtrack(0);
    return 0;
}*/
