#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    vector<int> input;
    int temp;
    while(!cin.eof()){
        cin>>temp;
        input.push_back(temp);
    }

    int s = input.size();

    int result[s], P[s], Pval[s], len;
    std::fill(result, result+s, -1);

    P[0] = 0;
    Pval[0] = input[0];
    len = 0;
    for(int i = 1; i < s; ++i){
        if(input[i] > Pval[len]){
            ++len;
            P[len] = i;
            Pval[len] = input[i];
            result[i] = P[len-1];
        } else if(input[i] < Pval[0]){
            P[0] = i;
            Pval[0] = input[i];
        } else{
            int index = lower_bound(Pval,Pval+len+1,input[i])-Pval;
            if(Pval[index] > input[i]){
                Pval[index] = input[i];
                P[index] = i;
                result[i] = P[index-1];
            }
        }
    }

    int l = P[len];
    stack<int> st;
    while(l > -1){
        st.push(input[l]);
        l = result[l];
    }
    cout<<len+1<<"\n-\n";
    while(!st.empty()){
        cout<<st.top()<<"\n";
        st.pop();
    }


    return 0;
}
