#include <iostream>
#include <vector>
using namespace std;

class heap{     /// MAX HEAP
private:
    vector<int> tomb;

    inline int szulo(int i){    /// felesleges egyelore
        return i/2;
    }

    inline int bal(int i){
        return i > 0 ? i*2 : 1;
    }

    inline int jobb(int i){
        return i > 0 ? i*2+1 : 2;
    }

    void heapify(int i){
        if(bal(i) >= tomb.size())
            return;

        int nagyobb = bal(i);
        if(jobb(i) < tomb.size() && tomb[jobb(i)] > tomb[nagyobb])
            nagyobb = jobb(i);

        if(tomb[i] > tomb[nagyobb])
            return;

        int temp = tomb[nagyobb];
        tomb[nagyobb] = tomb[i];
        tomb[i] = temp;

        heapify(nagyobb);
        return;
    }

public:
    void build_max_heap(vector<int> input){ /// O(n)
        tomb = input;
        for(int i = input.size()/2; i >= 0; --i){
            heapify(i);
        }
    }

    heap(vector<int> input){
        build_max_heap(input);
    }

    int get_max(){
        return tomb[0];
    }

    int extract_max(){
        int m = get_max();

        int temp = tomb[tomb.size()-1];
        tomb[tomb.size()-1] = tomb[0];
        tomb[0] = temp;

        tomb.pop_back();
        heapify(0);
        return m;
    }
};

int main()
{
    vector<int> be;
    for(int i = 0; i < 10; ++i)
        be.push_back(i);
    heap h(be);
    for(int i = 0; i < 10; ++i){
        cout<<h.extract_max()<<" ";
    }
    return 0;
}
