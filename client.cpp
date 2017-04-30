//Cody Herberholz, CS202, Program #3
//client.cpp
//This file contains the implementation of the Client, List, Graph, and Hash
//classes. Each class will contain constructor/destructors and the List, Graph, 
//and Hash will have the basic data structure functions allowing them to insert, 
//remove, remove all, retrieve, and display.



#include "client.h"



//Initializes Clients data members, calles the function to load all songs and 
//then sets the seed for random.
Client::Client():cll(0),graph(0),hash(0)  
{
    load_songs();
    srand(time(NULL));
}



//Deallocates Client's data members
Client::~Client()
{
    delete hash;    hash = NULL;
    delete graph;   graph = NULL;
//    delete cll;     cll = NULL;
}



//Task:   Creates an instance of all three data structures and then procedes to 
//        load in an object of Song into the Hash Table which is then filled in by an 
//        external data file. A Pointer is set to this object and sent into graph to 
//        give it access to Hash's Song without copying the data.
//Input:  None
//Output: Filled and complete data structures
void Client::load_songs()
{
    int tracker = 0; //Keeps track of if the insert into hash was successful
    Song temp; //Object of Song that is passed into hash
    Song * hold = &temp; //Pointer set to the Song object
    hash = new Hash;
    graph = new Graph;
//    cll = new List;

    ifstream read; 
    read.open("songs.txt"); //Opens file containing songs
    while(read && !read.eof())
    {
        tracker = hash->load_songs(read, temp);//Loads into hash table

        if(tracker)
            graph->load_songs(hold); //Loads into graph
    }
    read.close();
    read.clear();

}



//Task:   Acts as interface between program and user. Allows user to choose
//        to listen to favorite station, choose a station via artist/genre, or 
//        quit.
//Input:  None
//Output: Interface for user to use.
void Client::operation()
{
    int option = 0; //users choice from main menu
    int pick = 0; //users choice from secondary menu

    do
    {
        option = main_prompt();

        switch(option)
        {
            case 1:

                break;
            case 2:
                do
                {
                    pick = search_prompt();

                    if(pick == 1)
                       hash->retrieve(cll);

                    else if(pick == 2)
                        cout << "Not graph for you" << endl;
                }
                while(pick < 3 || pick > 3);

                break;
            case 3:
                cout << "Goodbye!" << endl;
        }
    }
    while(option != 3);

}



//Task:   Displays a menu to user to allow them to choose whether to play station
//        with all their liked songs, play songs from new artist/genre, or quit.
//Input:  None
//Output: Integer representing choice of user regarding their options from the menu
int Client::main_prompt()
{
    int choice = 0; //Keeps track of choice from main menu

    cout << "\n\n|----------Main Menu----------|" << endl;
    cout << "1) Play Favorite Station (Not Working)" << endl;
    cout << "2) Search for new Artist/Genre" << endl;
    cout << "3) Quit" << endl;

    cout << "\nPlease pick a number: ";
    cin >> choice;
    cin.ignore(100,'\n');

    return choice;
}



//Task:   Displays a menu to user to allow them to choose whether they want to 
//        play songs from an artist or genre type.
//Input:  None
//Output: Integer representing choice of user regarding their options from the menu
int Client::search_prompt()
{
    int choice = 0; //Keeps track of choice from menu

    cout << "\n\n|--------Search Menu--------|" << endl;
    cout << "1) Search Artist " << endl;
    cout << "2) Search Genre (Not Working) " << endl;
    cout << "3) Return to Main Menu " << endl;

    cout << "\nPlease pick a number: ";
    cin >> choice;
    cin.ignore(100, '\n');

    return choice;
}



//Constructor for List's data
List::List():rear(0)  {}



//Destructor which dealocates the list
List::~List()
{
//    L_node * current = rear->go_next();
//    rear->go_next() = NULL;
//    remove_all(current);
}



//Task:   Inserts a new L_node into the CLL
//Input:  None
//Output: None 
void List::insert()
{
    L_node * temp = NULL;
    L_node * current = NULL;

    if(!rear)
        rear = new L_node;
    else
    {
        temp = rear->go_next();
        current = new L_node;
        current->go_next() = temp;
        rear->go_next() = current;
    }
}



//Task:   Removes a L_node from the CLL
//Input:  
//Output: 
int List::remove()
{


    return 0;
}



//Task:   Removes all L_nodes within the CLL
//Input:  Inputs a L_node to recursivly traverse and delete the CLL
//Output: Returns what current's next pointer is pointing to and traverses recursivly
int List::remove_all(L_node *& current)
{
    if(!current) return 0;

    delete current;

    return remove_all(current->go_next());
}



//Task:   Retrieves a Song from a L_node
//Input: 
//Output:
int List::retrieve()
{

    return 0;
}



//Task:   Display Songs from the CLL
//Input:  None
//Output: Displays Songs
void List::display() const
{

}



//Constructor for the Graph Class. Reads in from the file and fills the vertex
//array with genres from the file after initializing the vertex array.
Graph::Graph(int gsize)
{
    ifstream read;
    read.open("songs.txt");
    
    alist = new Vertex[gsize];

    for(int i = 0; i < gsize; ++i)
        alist[i].load_genre(read);

    list_size = gsize;

    read.close();
    read.clear();
}



//Destructor for graph that deallocates the array of vertici
Graph::~Graph()
{
    delete [] alist;
}



//Task:   Loads song pointers into the graph that point to the song objects in
//        the hash table
//Input:  Pointer to Song object in Hash Table
//Output: Creates the edge relationships between the genres of songs
void Graph::load_songs(Song * to_attach)
{

    int index1 = 0; //First Genre location
    int index2 = 0; //Second Genre location

    index1 = find_location(to_attach);
    index2 = find_location(to_attach);

    alist[index1].insert(to_attach, alist, index2);
    alist[index2].insert(to_attach, alist, index1);
}



//Task:   Finds location of Song's genre within the Vertex array using compare
//Input:  Pointer to Song object living in Hash Table
//Output: Returns the index of song's genre withing vertex array
int Graph::find_location(Song * to_attach)
{
    int index = 50; //set to make array go out of bounds in case of failure
    int success = 0; //tracks success of genre match

    for(int i = 0; i < list_size; ++i)
    {
        success = alist[i].compare(to_attach);

        if(success)
            index = i; //sets element location to index
    }

    return index;
}



//Task:   Displays all the genre
//Input:  
//Output: Displays all genre
void Graph::display_vertices() 
{
    String temp;
    for(int i = 0; i < list_size; ++i)
        temp = alist[i].get_genre();
    cout << temp << endl;
}



//Task:   Displays songs based on the relationship of their genres
//Input:  
//Output: Displays songs randomly based on genre relationships
void Graph::display_adjacent() const
{

}


//Constructor that initializes the hash table to size hsize. Creates an array 
//of song pointers
Hash::Hash(int hsize)
{
    hash_table = new Song * [hsize];

    for(int i = 0;i < hsize;++i)
        hash_table[i] = NULL;
    hash_size = hsize;

}



//Deallocates the Hash table in its entirety
Hash::~Hash()
{
    if(!hash_table) return;
    Song * temp = NULL;
    Song * current = NULL;

    for(int i = 0; i < hash_size;++i)
    {
        temp = hash_table[i];

        while(temp)
        {
            current = temp->go_next();
            delete temp;
            temp = current;
        }
    }
    delete [] hash_table;
}



//Task:   Loads songs into hash table 
//Input:  Read to help read from files and then a Song to fill and set in the 
//        hash table.
//Output: Returns one upon success
int Hash::load_songs(ifstream & read, Song & to_add)
{
    int index = 0; //captures the number gathered from the hash function
    Song * current = new Song; //Song object created to be part of hash table

    current->insert(read, to_add); 

    if(read.eof())
    {
        delete current;
        return 0;
    }
    else
    {
        index = current->hash_artist();
        index = index % hash_size;
        
        if(!hash_table[index])
            hash_table[index] = current;

        else
        {
            current->go_next() = hash_table[index];
            hash_table[index] = current;
        }
    }
    return 1;  
}



//Task:   Retrieves a song from the hash table. Asks the user what artist they 
//        want and then hashes it to get to the index. 
//Input:  Pointer to List to ensure that I can begin to build my CLL when they
//        like a song.
//Output: Displays a song from the hash table
int Hash::retrieve(List * playlist)
{
    int length = 0; //captures the length of the artist asked for
    int index = 0; //holds the hashed value
    String search; //holds artist being asked for temporarily

    cout << "Please enter in the artist you would like to search for: " << endl;
    cin >> search;
    cin.ignore(100, '\n');

    length = search.get_size();

    for(int i = 0; i < length; ++i)
        index += search[i];

    index = index % hash_size;
    cout << *hash_table[index];

    hash_table[index]->rate(playlist); //Allows user to like or dislike song

    return 1;
}

