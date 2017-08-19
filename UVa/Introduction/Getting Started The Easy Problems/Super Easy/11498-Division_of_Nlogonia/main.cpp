#include <iostream>

using namespace std;

struct koord{
public:
    int x;
    int y;

    koord(){}

    koord(int _x, int _y){
        x = _x;
        y = _y;
    }

    //friend ostream& operator<<(ostream& os, const Date& dt);
};

koord operator-(koord& bal, koord& jobb){
    koord eredmeny;
    eredmeny.x = bal.x-jobb.x;
    eredmeny.y = bal.y-jobb.y;
    return eredmeny;
}

ostream& operator<<(ostream& s, const koord& k){
    s<<"x: "<<k.x<<" y: "<<k.y<<"\n";
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int db;


    /*koord a(3,5);
    koord b(1,2);
    koord c = a-b;*/

    //cout<<c.x<<" "<<c.y<<"\n";
    //cout<<c;

    cin>>db;
    koord kozep, be;
    while(db != 0){
        cin>>kozep.x>>kozep.y;
        for(int i = 0; i < db; i++){
            cin>>be.x>>be.y;

            be = be - kozep;
            if(be.x == 0 || be.y == 0){
                cout<<"divisa\n";
            } else{
                if(be.y<0)
                    cout<<"S";
                else
                    cout<<"N";

                if(be.x<0)
                    cout<<"O\n";
                else
                    cout<<"E\n";
            }

        }
        cin>>db;
    }
    return 0;
}
