using namespace std;
#include "funtions.hpp"
#include "reader.hpp"

int main(int argc, char** argv){
    
    Battalion data[1000];
    load_data(data);

    /*
    for(int i = 0; i < 1000; ++i){
        cout << i << ": " << data[i].getCode() << "-" << data[i].getId() << endl;
    }
    */
   for (int i = 0; i < 1000; i++)
   {
    insert(root, data[i]);
   }

    cout<<"\n Buscar recursivo";
    (find(root,20)) ? cout<<"\n El valor buscado si existe \n" : cout<<"\n El valor buscado NO encontrado \n"; 

    cout<<"\n Buscar NO recursivo \n";
    findNoRecursive(root,20);

    show(root, PRE);
   

    return 0;
}