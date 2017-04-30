//Cody Herberholz, CS202, Program #3
//main.cpp
//This Program is called CS Pandora. Its purpose is to provide a program similar
//to pandora. There will be a graph that maintains genre relationships, Hash
//Table that maintains Artists but will branch out a little due to some collisions
//to provide variety, and then CLL to provide a favorite station full of liked
//songs and if the user unlikes them they will be removed from that list. This
//file is main and it takes care of giving a title to the program and then 
//starting by calling upon operation to provide the user with a menu interface.



#include "client.h"



int main()
{
    cout << "\nWelcome to CSPandora!" << endl << endl;
   
    Client start;

    start.operation();

    return 0;
}
