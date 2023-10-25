#include <iostream>
#include "funtions.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    string words[] = {"hola", "ola", "hoja", "ave", "tristeza", "lluvia", "avenida", "astilla", "otono", "lluvisna"};
    int option;
    bool continue_menu=true;
    //getting the size of array
    int numElements = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < numElements; i++) {
        insert(root, words[i]);
    }
    cout<<"Added some words of tree \n";
    do
    {
        cout<<"Option:\n 1-Insert word \n 2-Autocomplete \n 3-Print all \n" ;
        cin>>option;
        
        switch(option){
            case 1: cout<<"You chose option  1"<<endl; addWord(); break;
            case 2: cout<<"You chose option  2"<<endl;autocomplete(); break;
            case 3: cout<<"You chose option  3 \n"; printAll(); break;
            case 4: cout<<"salir"<<endl; continue_menu=false; break;
            default: cout<<"Error al ingresar datos"<<endl;
        }

    }while (continue_menu);
    

    return 0;
}