#include <iostream>
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    while(!cin.eof()){
        string bemenet;
        cin>>bemenet;

        //cout<<"bemenet: "<<bemenet<<"\n";
        if(bemenet == "")
            break;                      /// A bemenet utolso sora ures
        list<char> kimenet;
        int meret = bemenet.length();
        list<char>::iterator it = kimenet.begin();
        for(int i = 0; i < meret; i++){
            if(bemenet[i] == '[')
                it = kimenet.begin();   /// begin() az elso elemre mutato iteratorral ter vissza
            else if(bemenet[i] == ']')
                it = kimenet.end();     /// end() az utolso elem utani helyre mutato iteratorral ter vissza
            else{
                it = kimenet.insert(it,bemenet[i]); /// Beillesztes it ele, instert(...) visszateresi erteke a beillesztett elemre
                                                    /// mutato iterator.
                it++;                               /// Atlepi az eppen beillesztett elemet, hogy kesobb utana illeszthessen
            }
        }

        it = kimenet.begin();
        while(it != kimenet.end()){     /// Addig kell menni amig el nem erjuk a veget
            cout<<*it;                  /// it ertekenek kiirasa (mintha pointer lenne)
            it++;
        }
        cout<<"\n";
    }

    return 0;
}
