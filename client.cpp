//Cody Herberholz, CS202, Program #3
//client.cpp



#include "client.h"
//using namespace std;



//
Client::Client():cll(0),graph(0),hash(0)  {}



//
Client::~Client()
{


}



//
void Client::operation()
{
    int option = 0;
/*    String test,other;
    cout << "\nTime to insert into a string: ";
    cin >> test;
    cin.ignore(100,'\n');
    cout << endl;
    cout << test;
    other = test;
    cout << "Other: " << other << endl;
*/    
    cout << "\nWelcome to CSPandora!" << endl;

    do
    {
        option = prompt();

        switch(option)
        {
            case 1:

                break;
            case 2:

                break;
            case 3:
                cout << "Goodbye!" << endl;
        }

    }
    while(option != 3);

}



//
int Client::prompt()
{
    int choice = 0;

    cout << "\n\n|----------Main Menu----------|" << endl;
    cout << "1) Play Favorite Station" << endl;
    cout << "2) Search for new Artist/Genre" << endl;
    cout << "3) Quit" << endl;

    cout << "\nPlease pick a number: ";
    cin >> choice;
    cin.ignore(100,'\n');

    return choice;
}




//
List::List():rear(0)  {}



//
List::~List()
{


}



//
int List::insert()
{


    return 0;
}



//
int List::remove()
{


    return 0;
}



//
int List::remove_all()
{

    return 0;
}



//
int List::retrieve()
{

    return 0;
}



//
void List::display() const
{

}



//
Graph::Graph(int gsize)
{
    alist = new Vertex[gsize];

    for(int i = 0; i < gsize; ++i)
        alist[i].set_null();

    list_size = gsize;

}



//
Graph::~Graph()
{

}



//
int Graph::insert_edge(char * current_vertex, char * to_attach)
{

    return 0;
}



//
int Graph::find_location(char * key_value)
{

    return 0;
}



//
void Graph::display_vertices() const
{

}



//
void Graph::display_adjacent() const
{

}


//
Hash::Hash(int hsize)
{
    hash_table = new Song * [hsize];

    for(int i = 0;i < hsize;++i)
        hash_table[i] = NULL;
    hash_size = hsize;

}



//
Hash::~Hash()
{
    

}



//
int Hash::retrieve(char * search_song)
{

    return 0;
}

